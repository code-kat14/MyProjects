// GET on /birth_date. This action will give Frank Sinatra birth date.
// GET on /birth_city. This action will give Frank Sinatra birth city.
// GET on /wives. This action will give all the name of Frank Sinatra wife.
// Get on /picture will redirect you to a picture of frank sinatra
// Get on /public will be a public webpage everybody can see 
// Get on /protected will give you either a welcome message or Not authorized message based on correct login

import express from 'express' 
import basicAuth from 'express-basic-auth'
const app = express()
const port = 8080

console.log("server started")

let birthday = "December 12, 1915";
let birthcity = "Hoboken, New Jersey";
let wives = "Nancy Barbato, Ava Gardner, Mia Farrow, Barbara Marx";

//GET a random song of sinatra
app.get('/', (req, res) => {
    console.log("from the /");
    let sinatrasongs = ['Tell Me at Midnight', 'Tenderly','Before the Music Ends','Be Careful, It\'s My Heart','The Beautiful Strangers',
'Baubles, Bangles and Beads','Bang Bang (My Baby Shot Me Down)','Baby, Won\'t You Please Come Home?',
'Bad, Bad Leroy Brown','At Least a Little in Love','At Long Last Love','Autumn in New York','Autumn Leaves',
'Available','Ave Maria','Azure-Te (Paris Blues)','A Baby Just Like You','Ain\'t Cha Ever Comin\' Back?',
'Ain\'t She Sweet','After You\'ve Gone'];

function songIndex() {
    return Math.floor(Math.random() * sinatrasongs.length);
}

function pickRandomSong() {
    let randomIndex = songIndex();
    let randomSong = sinatrasongs[randomIndex];
    return randomSong;
} 
    res.send(`${pickRandomSong()}`);  
})

app.get("/birth_date", (req, res) => {
    console.log("from /birth_date")
    res.send(`${birthday}`)
})

app.get("/birth_city", (req, res) => {
    console.log("from /birth_city")
    res.send(`${birthcity}`)
})

app.get("/wives", (req, res) => {
    console.log("from /wives")
    res.send(`${wives}`)
})

//--- redirect to his picture
app.get("/picture", (req, res) => {
    console.log("from /picture")
    res.redirect('https://en.wikipedia.org/wiki/Frank_Sinatra#/media/File:Frank_Sinatra2,_Pal_Joey.jpg')
})

app.get("/public", (req,res)=>{
    console.log("public")
    res.send("Everybody can see this page")
})

app.use(basicAuth({
    users : {'admin': 'admin'},
    unauthorizedResponse : (req) => {
        if (req.auth && req.auth.username == 'admin' && req.auth.password == 'admin') 
        {
            return "Welcome, authenticated client";
        } 
        else 
        {
            return "Not authorized";
        }
    }

}))

app.get("/protected",(req,res)=>{

res.status(200).send("Welcome, authenticated client")

});

app.listen(port, '0.0.0.0', () => {
    console.log(`app.js listening on ${port}`);
});

// curl -i http://admin:admin@localhost:8080/protected 
// curl -i http://admin:wrong@localhost:8080/protected 
