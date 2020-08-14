<?php

if(!defined('REAL')){exit('access denied');}

function auth($login, $password){
    $check = db_query(
        3,
        'SELECT COUNT(*) FROM '.$GLOBALS['CONFIG']['DB']['SCHEMA'].'`user` WHERE `login_user` = ? AND `password_user` = ?',
        array($login, md5($password))
    );

    if($check){
        return true;
    }else{
        return false;
    }
}

function unauth(){
    unset($_SESSION['AUTH']);
}