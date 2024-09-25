function getFirestore(){
  var email = "xdeste-accountsheets@xdeste-efb3c.iam.gserviceaccount.com";
  var key = "-----BEGIN PRIVATE KEY-----\nMIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQCcJUqDoW+7bLNz\ndWmRhEm5y7M8ZZxDdYRQdtZz3cmfJxyu7Cwecn4aqgBuMsiQqrotWThHpe66EYbw\n2BLniolUddUnzDvJrd4wcSjwhg3S8N/q1YWAuaN7/C5zl57puH9/rXPyKGX+4Xvt\nCySlHuOKF2SfGBAHQP2Kuu9KqnPgHtrysh2WYnopajVGrbpOJ8ORU46GzfmTLEXE\nX4qHsqi10akIhJO7tXqEhdwj6zM0s9WQd8XGhWFa7vHZ11IvldSz8R6RjOdYzmMo\nYQCscNsVyzeVhb0EzIUPTplFLaeo2GEzifv0jsmSVkuL+nZBSTCTHHV1UbUVJNP3\nlAhS/stfAgMBAAECggEAKW/8BlKhRCvks49FJMjmh9f3COAuR/i31GK1JqqFBydq\nBUHHs4zOymSzGIuBjmLAZah3twvh/p8IIII3AhtRtohOuPEKLMtnW5OsOahZotEp\nmzhu5WpeaFjUOvjRw1SjAU8WpfzylGFicdWzM96uo8bxfQb1ufcVUeup9Tam6aLc\nY0uvsFtOc6d2GQ3JQcWRdYk8rZlbnDeu0ssvcEUR1lODbiB2Yh3sby2HCrwEXMUq\nxX6QNHANy99RlNX44kcsN37xMVFXzADesxYokYgVRIFidW1G7BDgI7clnhMjya+j\nakn/aoElZq6Kxg6XlAtkfTmC6xvMLQuWNdrfmAPIgQKBgQDQRnbSrXV6vFhUpJ18\n33a5J/UcrMFjUCXDYo+/DbgxsZuN5B651TlN0gbJQQGYBXAaui8BVH3O/2H+Fzkw\nolcqamXNZDnKQezNskobMio2T6NbXoQnJIlx9SrjSfknXBvPYt8po152vVbW+ZWe\nZmvQvARnElTBIwB7nfWyH+H6ewKBgQC/7ODQCBY6yj63aT+LKEqLx2psVZp221ow\nRSrnkbLWs5aFkZ4SYokmJUdm15AgHmcuUNkNLIzWeup8xCez6vonXO1lqaMNlbGe\nHe/dl7SG6hdFn5On33DRzFBSDES5VwxzScH+huB8oz9B3o+9rKkzb/hCmh3RMhYq\no8nTcuLfbQKBgQC1gqNtaeQ3actlQO1LdYiHRs50Bg6n2aJ/i/cQnwlGra2OVB9+\n/tdo/cASRsf3z81qTZZHh3X5H1IsWdrqiqCCg6VjAZTnstqITXgOCYMGQBNyvoVX\ng50RJoQQ/1fXOIu4CkfIhur9enci9PKy0Dnn+OOxXCVnCHUURo5ohSaw3wKBgBH2\no9wUxa/e+hvEmBP4Q3HtykI1iO2S/lACSU+/TVPXH0GFLZxe6KNPXe18Q5sd/V5S\nZt5ayxvQCV6AJY8rcRp6EiYvyHkfB67a8nZ1Gop+Iot7siBGQ5L/Yo0rZMtMIHgx\n8RxXl29TADq0EBQaswODeWMSdbP80iJPjjZiTGXJAoGBAIJF18gxIllMM0h8FV/0\nsOoNz1Vrzxk/fX/0P1oIKa2M5qIwFoa2uW8vmAIwJNwEpeWYYL9qc1GrTATURrLq\nYelgrlDLSQAtUcTnsLJouzArsD0CnrXZ3Niu2wwPjFWBme143bicHQpxUv1gWyxU\n2WUjbWr54MrIOuTuS1buqCDF\n-----END PRIVATE KEY-----\n";
  var projectId = "xdeste-efb3c";
  return FirestoreApp.getFirestore(email,key,projectId);
}

function myFunction() {
  const firestore=getFirestore();
  var ss = SpreadsheetApp.getActiveSpreadsheet();
  var sheetname = "database";
  var sheet = ss.getSheetByName(sheetname);
  //la ultima fila se indica en la celda K2
  var lastRow = sheet.getRange("K2").getValue();
  //la ultima columna es la G en numero
  var lastColumn = 7;
  var data = sheet.getRange(2,1,lastRow, lastColumn).getValues();
  /*Los datos se guardaran en firebase con el siguiente formato
  id: { (dato de la columna B)
    "nombre": "nombre", (dato de la columna C)
    "legajo": 12345, (dato de la columna D)
    "auth": true, (dato de la columna E)
    "authA": true, (dato de la columna F)
    "authB": true, (dato de la columna G)
  }
  */
  var dataToSave = {};
  for (var i = 0; i < data.length; i++) {
    var id = data[i][1];
    dataToSave[id] = {
      "nombre": data[i][2],
      "legajo": data[i][3],
      "auth": data[i][4],
      "authA": data[i][5],
      "authB": data[i][6]
    }
  }
  firestore.createDocument("users",dataToSave);
}

function sendDataToFirebase() {
  // URL de Firebase Realtime Database
  const firebaseUrl = 'https://esp8266database-aff3b-default-rtdb.firebaseio.com';

  // Obtener los datos de la hoja
  const sheet = SpreadsheetApp.getActiveSpreadsheet().getActiveSheet();
  const data = sheet.getDataRange().getValues();
  
  // Configurar los datos en formato JSON
  const jsonData = [];
  
  // Saltar la primera fila si son encabezados
  for (let i = 1; i < data.length; i++) {
    let rowData = {
      'columna1': data[i][0],  // Cambia 'columna1' por el nombre adecuado
      'columna2': data[i][1],  // Cambia 'columna2' por el nombre adecuado
      'columna3': data[i][2]   // Agrega tantas columnas como sea necesario
    };
    jsonData.push(rowData);
  }

  // Convertir datos a JSON
  const payload = JSON.stringify(jsonData);

  // Enviar los datos a Firebase
  const options = {
    method: 'put',  // Puedes usar 'post' si prefieres agregar los datos
    contentType: 'application/json',
    payload: payload
  };

  const response = UrlFetchApp.fetch(firebaseUrl + '/datos.json', options);
  Logger.log(response.getContentText());
}