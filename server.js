const express = require('express');
const fm19js = require('./build/Release/fm19js.node');
const app     = express();
const port    = 3000;

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
// Declare static folder to be served. It contains the js, images, css, etc.
app.use(express.static('app'));
app.route('/*')
    .get((req, res) => {
        res.sendFile(__dirname + '/index.html');
    });

app.listen(port, () => console.log(`Example app listening on port ${port}!`));




