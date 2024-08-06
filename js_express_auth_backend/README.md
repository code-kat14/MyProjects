# Welcome to My First Backend
***

## Task
Create a backend app with express js to give you various information about frank sinatra 
we well as add basic authentication<br>

## Description
Using the get method to navigate to the various information you want to get about frank sinatra.
I used express basicauth to provide basic authentication, although it is not recommended to use basicauth
as its not secure.<br> 

## Installation
You can install json package if you are using a json body parser. <br>
For this version of the app, I am using express-basic-auth.<br>
you will need to download the express basic auth by run the following command->
```
npm install express-basic-auth 
```
## Usage
using the following curl commands it will direct you to the coorisponding pages with the following command<br>
in your terminal-> 
```
curl -i http:localhost:8080/*the page you want to go to* 
```
on / will give you a random song out of a list of 20 by frank sinatra<br>
/birth_date gives you sinatras brithday<br>
/birth_city gives you sinatras bity of birth<br>
/wives gives you sinatras wives<br>
/picture will redirect you to a picture of sinatra <br>
/public will display a "everybody can see this message" no credentials needed <br>
/protected will send a status 200 welcome message if credentials are correct, or a 401 status if credentials are not correct.<br>
```
./my_project app.js random_songs.js 
```

### The Core Team

<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
