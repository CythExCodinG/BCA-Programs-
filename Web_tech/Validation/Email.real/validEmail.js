function validate(phone, email, pass, cPass) {
  console.log(phone);
  var emailformat = /^[a-zA-Z0-9!#$%&-]+@[a-zA-Z0-9-]+.[a-zA-Z0-9-]+$/;
  var phoneformat = /^\d{10}$/;
  var arr = [0, 0, 0];

  if (phone.match(phoneformat)) {
    arr[0] = 1;
  }

  if (email.match(emailformat)) {
    arr[1] = 1;
  }

  if (pass == cPass && pass != "") {
    arr[2] = 1
  }

  const message =
    `
    ${arr[0] == 1 ? "Phone No : Valid\n" : "Phone No : inValid\n"}
    ${arr[1] == 1 ? "Email : Valid\n" : "Email: inValid\n"}
    ${arr[2] == 1 ? "Password : Matched" : "Password : Mis-Matched"}
  `;
  alert(message);
  return false;
}
