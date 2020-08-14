<?php

define('REAL', true);

session_start();

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

require_once 'engine/config.inc';
require_once 'engine/db.inc';
require_once 'engine/function.inc';
require_once 'engine/controller.inc';