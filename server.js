const express = require('express');
const fm19js = require('./build/Release/fm19js.node');
const app     = express();
const port    = 3000;

app.route('/api/service/myProfile').get((req, res) => {
    res.send(fm19js.myProfile());
});


// Declare static folder to be served. It contains the js, images, css, etc.
app.use(express.static('app'));
app.route('/*')
    .get((req, res) => {
        res.sendFile(__dirname + '/index.html');
    });

app.listen(port, () => console.log(`Example app listening on port ${port}!`));




