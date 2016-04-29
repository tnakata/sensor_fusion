var express = require('express');
var router = express.Router();
var fs = require('fs');
//const addon = require('../addons/c++/SensorFusion/build/Release/addon');

/* GET users listing. */
router.get('/', function(req, res, next) {
  var id = req.query.id;

  if(id == {})
  	res.send('Please Input request ID');
  else {
	var ori = fs.readFileSync('executable/orientation_reading.txt');
  	res.send(ori.toString());
  }
  console.log('REST request with ID of ' + id);
});

module.exports = router;
