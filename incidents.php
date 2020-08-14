<?php

date_default_timezone_set('Europe/Kiev');

define('REAL', true);

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

require_once 'engine/config.inc';
require_once 'engine/db.inc';

$time = 30; // check every xx seconds

header('Refresh:'.$time);

//COMBINE TO TRUCK
$data = db_query(1, '
SELECT 
uctt.*, 
wc.id_employee AS id_employee, 
wc.id_affiliate AS id_affiliate, 
wc.id_combine AS id_combine, 
wc.coordinates_combine AS coordinates_combine, 
wt.current_department_truck AS current_department_truck, 
wt.id_truck AS id_truck 
FROM '.$CONFIG['DB']['SCHEMA'].'unloading_combine_to_truck AS uctt  
JOIN '.$CONFIG['DB']['SCHEMA'].'working_combine AS wc ON wc.id_working_combine = uctt.id_working_combine 
JOIN '.$CONFIG['DB']['SCHEMA'].'working_truck AS wt ON wt.id_working_truck = uctt.id_working_truck 
', array());

foreach ($data as $d) {
    if($d['datetime_unloading_combine_to_'] > date('Y-m-d H:i:s', time()-$time)) {
        if (($d['current_department_truck'] - $d['last_truck_size']) < $d['size_combine_to_truck']) {
            //INCIDENT
            echo '<hr>#' . $d['id_unloading_combine_to_truck'] . ' Incident! - ' . $d['datetime_unloading_combine_to_'].' - '.date('Y-m-d H:i:s', time()-$time);

            db_query(2, 'INSERT INTO '.$CONFIG['DB']['SCHEMA'].'incident
            (shortage, datetime_incident, coordinates_incident, id_truck, id_combine, id_employee, id_affiliate, type_incident)
            VALUES (?, ?, ?, ?, ?, ?, ?, ?) 
', array(
    ($d['size_combine_to_truck'] - ($d['current_department_truck'] - $d['last_truck_size'])),
                $d['datetime_unloading_combine_to_'],
                $d['coordinates_combine'],
                $d['id_truck'],
                $d['id_combine'],
                $d['id_employee'],
                $d['id_affiliate'],
                1
            ));
        } else {
            //OK
        }
    }else{
        //OLD
    }
}

//TRUCK TO ELEVATOR
$data = db_query(1, '
SELECT 
utte.*, 
wt.id_employee AS id_employee, 
wt.id_affiliate AS id_affiliate, 
wt.coordinates_truck AS coordinates_truck, 
wt.current_department_truck AS current_department_truck, 
wt.id_truck AS id_truck, 
e.current_volume_elevator AS current_volume_elevator 
FROM '.$CONFIG['DB']['SCHEMA'].'unloading_truck_to_elevator AS utte  
JOIN '.$CONFIG['DB']['SCHEMA'].'working_truck AS wt ON wt.id_working_truck = utte.id_working_truck 
JOIN '.$CONFIG['DB']['SCHEMA'].'elevator AS e ON e.id_elevator = utte.id_elevator
', array());

foreach ($data as $d) {
    if($d['datetime_unloading_truck_to_el'] > date('Y-m-d H:i:s', time()-$time)) {
        if (($d['current_volume_elevator'] - $d['last_elevator_size']) < $d['size_truck_to_elevator']) {
            //INCIDENT
            echo '<hr>#' . $d['id_unloading_truck_to_elevator'] . ' Incident! - ' . $d['datetime_unloading_truck_to_el'].' - '.date('Y-m-d H:i:s', time()-$time);

            db_query(2, 'INSERT INTO '.$CONFIG['DB']['SCHEMA'].'incident
            (shortage, datetime_incident, coordinates_incident, id_truck, id_combine, id_employee, id_affiliate, type_incident)
            VALUES (?, ?, ?, ?, ?, ?, ?, ?) 
', array(
                ($d['size_truck_to_elevator'] - ($d['current_volume_elevator'] - $d['last_elevator_size'])),
                $d['datetime_unloading_truck_to_el'],
                $d['coordinates_truck'],
                $d['id_truck'],
                $d['id_elevator'],
                $d['id_employee'],
                $d['id_affiliate'],
                2
            ));
        } else {
            //OK
        }
    }else{
        //OLD
    }
}