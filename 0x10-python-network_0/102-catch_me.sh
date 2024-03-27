#!/bin/bash

# Make a request to 0.0.0.0:5000/catch_me
response=$(curl -s -X PUT "0.0.0.0:5000/catch_me" -d "user_id=98" --header "Origin: HolbertonSchool")

# Extract the message containing "You got me!" from the response
message=$(echo "$response" | grep -o "You got me!")

# Output the message
printf "%s\n" "$message"

