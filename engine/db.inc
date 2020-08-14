<?php

if(!defined('REAL')){exit('access denied');}

try {
    $db = new PDO('pgsql:host='.$CONFIG['DB']['HOST'].';dbname='.$CONFIG['DB']['NAME'], $CONFIG['DB']['USER'], $CONFIG['DB']['PASSWORD']);
    //$db = new PDO('mysql:host='.$CONFIG['DB']['HOST'].';dbname='.$CONFIG['DB']['NAME'].';charset=utf8', $CONFIG['DB']['USER'], $CONFIG['DB']['PASSWORD']);

    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
}
catch(PDOException $e) {
    exit('Проблема з базою: ' . $e->getMessage());
}

function db_query($type, $query, $data){
    $query = $GLOBALS['db']->prepare(str_replace('`', '', $query));

    $result = $query->execute($data);

    if($type == 1) {
        return $query->fetchAll(PDO::FETCH_ASSOC);
    }else if($type == 2) {
        return $result;
    }else if($type == 3) {
        return $query->fetchAll(PDO::FETCH_ASSOC)[0]['count'];
    }
}