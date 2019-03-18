const express = require('express');
const fm19js = require('./build/Release/fm19js.node');
const app     = express();
const port    = 3000;
const fs = require('fs');
const path = require('path');




function fmPlayerDetailLoader() {
    const filePath = __dirname + '/app/assets/json/player-details/fullplayer.json';
    console.log("fm19js.playerIDList()",fm19js.playerIDList());
    return;

    fs.truncate(filePath, 0, function(){console.log('done')});

    fs.appendFile(filePath,  JSON.stringify(fm19js.playerIDList()), function(err) {
        if (err) { throw err }
    });


}
function fmPlayerDtLoader(){
    const filePath = __dirname + '/app/assets/json/playerdt.json';

    fs.truncate(filePath, 0, function(){console.log('done')});

    fs.appendFile(filePath,  JSON.stringify(fm19js.playerDatatable()), function(err) {
        if (err) { throw err }
    });
}

app.route('/api/service/fmLoader').get((req, res) => {
    fmPlayerDetailLoader();
    //fmPlayerDtLoader();
    res.send("ok");
});


app.route('/api/service/myProfile').get((req, res) => {
    res.send(fm19js.myProfile());
});

app.route('/api/service/currentClub').get((req, res) => {
    res.send(fm19js.currentClub());
});


app.get('/api/service/player/:playerId', function (req, res) {
    let playerId =parseInt(req.params.playerId);
    res.send(fm19js.player(playerId));
});


app.get('/api/service/playerDatatable', function (req, res) {


    res.send("ok");
});

// Declare static folder to be served. It contains the js, images, css, etc.
app.use(express.static('app'));
app.route('/*')
    .get((req, res) => {
        res.sendFile(__dirname + '/index.html');
    });

app.listen(port, () => console.log(`Example app listening on port ${port}!`));




