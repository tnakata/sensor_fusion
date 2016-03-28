var express = require('express');
var router = express.Router();
const addon = require('../addons/c++/SensorFusion/build/Release/addon');

/* GET users listing. */
router.get('/', function(req, res, next) {
  var id = req.query.id;

  if(id == {})
  	res.send('Please Input request ID');
  else {
  	res.send(addon.hello());
  }
  console.log('REST request with ID of ' + id);
});

module.exports = router;
