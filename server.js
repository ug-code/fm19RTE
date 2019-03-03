const express = require('express');
const app     = express();
const port    = 3000;

app.route('/api/service/myProfile').get((req, res) => {
    res.send({
        cats: [{ name: 'lilly' }, { name: 'lucy' }]
    });
});


// Declare static folder to be served. It contains the js, images, css, etc.
app.use(express.static('app'));
app.route('/*')
    .get((req, res) => {
        res.sendFile(__dirname + '/index.html');
    });

app.listen(port, () => console.log(`Example app listening on port ${port}!`));

// This file is required by the index.html file and will
// be executed in the renderer process for that window.
// All of the Node.js APIs are available in this process.
// hello.js
const fm19js = require('./build/Release/fm19js.node');
console.log(fm19js.myProfile()); // 'world'

