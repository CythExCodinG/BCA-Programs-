function validate(name, phone) {
  var phoneformat = /^\d{10}$/;
  var nameformat = /^[a-zA-Z-]+$/;

  if (name.match(nameformat)) {
    alert("Valid Name Entered");
  }
  else {
    alert("Invalid Name");
  }

  if (phone.match(phoneformat)) {
    alert("Valid Phone No");
  }
  else {
    alert("Invalid NO");
  }
  return false
}
