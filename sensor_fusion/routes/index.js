var express = require('express');
var router = express.Router();
var bodyParser = require('body-parser');

router.use(bodyParser.json());
router.use(bodyParser.urlencoded({ extended: false }));

/* GET home page. */
router.get('/', function(req, res, next) {
	console.log('Home page GET request detected');
	res.render('index', { title: 'Express' });
});

/* POST home page. */
router.post('/', function(req, res) {
	console.log('Home page POST request detected');
	var proc_id = req.body.id;
	var msg = 'Process completed with ID of ' + proc_id;
	res.json({msg: msg});
});

module.exports = router;
