#!/usr/bin/node

const request = require('request');

// Get the movie ID from the command line arguments
const movieId = process.argv[2];

// Define the API URL for fetching the movie details
const apiUrl = `https://swapi.dev/api/films/${movieId}/`;

// Fetch the movie details
request(apiUrl, (error, response, body) => {
  if (error) {
    console.error('Error fetching movie details:', error);
    return;
  }

  // Parse the response body as JSON
  const movie = JSON.parse(body);

  // Get the list of character URLs
  const characters = movie.characters;

  // Fetch and print each character's name
  characters.forEach((characterUrl) => {
    request(characterUrl, (error, response, body) => {
      if (error) {
        console.error('Error fetching character details:', error);
        return;
      }

      // Parse the character details
      const character = JSON.parse(body);
      console.log(character.name);
    });
  });
});

