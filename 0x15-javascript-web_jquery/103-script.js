$(document).ready(function() {
  // Function to fetch and display the greeting
  function fetchGreeting() {
    var languageCode = $('#language_code').val();
    var apiUrl = 'https://www.fourtonfish.com/hellosalut/hello/';

    $.get(apiUrl, { lang: languageCode }, function(data) {
      $('#hello').text(data.hello);
    });
  }

  // Event listener for the button click
  $('#btn_translate').click(function() {
    fetchGreeting();
  });

  // Event listener for pressing Enter key in the input field
  $('#language_code').keypress(function(event) {
    if (event.which == 13) {
      fetchGreeting();
    }
  });
});

