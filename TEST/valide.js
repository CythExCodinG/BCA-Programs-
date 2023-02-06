function valid(email) {
  var mailformat = /^[a-zA-Z0-9!#$%-]+@[a-zA-Z0-9-]+.[a-zA-Z-]+$/;
  console.log(email);
  if (email.match(mailformat)) {
    alert("EMAIL VALID");
  } else {
    alert("INVALID EMAIL");
  }
}