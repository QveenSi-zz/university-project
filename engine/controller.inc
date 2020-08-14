<?php

if(!defined('REAL')){exit('access denied');}

if(isset($_SESSION['AUTH']) && $_SESSION['AUTH']) {
    if(isset($_GET['unauth'])){
        unauth();
        header('Location: /');
        exit();
    }

    if(isset($_GET['get'])) {
        switch ($_GET['get']) {
            case 'employee':
                $data = db_query(1, 'SELECT * FROM '.$CONFIG['DB']['SCHEMA'].'`employee` ORDER BY `id_employee`', array());

                echo json_encode($data);
                break;

            case 'trucks':
                $data = db_query(1, 'SELECT * FROM '.$CONFIG['DB']['SCHEMA'].'`truck` ORDER BY `id_truck`', array());

                echo json_encode($data);
                break;

            case 'combines':
                $data = db_query(1, 'SELECT * FROM '.$CONFIG['DB']['SCHEMA'].'`combine` ORDER BY `id_combine`', array());

                echo json_encode($data);
                break;

            case 'elevators':
                $data = db_query(1, 'SELECT * FROM '.$CONFIG['DB']['SCHEMA'].'`elevator` ORDER BY `id_elevator`', array());

                echo json_encode($data);
                break;

            case 'combines-active':
                $data = db_query(1, '
SELECT 
wc.*, 
c.state_number_combine AS state_number_combine, 
c.serial_number_combine AS serial_number_combine, 
c.department_combine AS department_combine, 
e.name_employee AS name_employee, 
e.surname_employee AS surname_employee, 
e.position_employee AS position_employee, 
e.phone_number_employee AS phone_number_employee, 
a.name_affiliate AS name_affiliate, 
a.adress_affiliate AS adress_affiliate, 
a.phone_number AS phone_number_affiliate 
FROM '.$CONFIG['DB']['SCHEMA'].'working_combine AS wc 
JOIN '.$CONFIG['DB']['SCHEMA'].'combine AS c ON c.id_combine = wc.id_combine
JOIN '.$CONFIG['DB']['SCHEMA'].'employee AS e ON e.id_employee = wc.id_employee 
JOIN '.$CONFIG['DB']['SCHEMA'].'affiliate AS a ON a.id_affiliate = wc.id_affiliate 
' , array());

                echo json_encode($data);
                break;

            case 'trucks-active':
                $data = db_query(1, '
                SELECT 
wt.*, 
t.state_number_truck AS state_number_truck, 
t.serial_number_truck AS serial_number_truck, 
t.department_truck AS department_truck, 
e.name_employee AS name_employee, 
e.surname_employee AS surname_employee, 
e.position_employee AS position_employee, 
e.phone_number_employee AS phone_number_employee, 
a.name_affiliate AS name_affiliate, 
a.adress_affiliate AS adress_affiliate, 
a.phone_number AS phone_number_affiliate 
FROM '.$CONFIG['DB']['SCHEMA'].'working_truck AS wt 
JOIN '.$CONFIG['DB']['SCHEMA'].'truck AS t ON t.id_truck = wt.id_truck
JOIN '.$CONFIG['DB']['SCHEMA'].'employee AS e ON e.id_employee = wt.id_employee 
JOIN '.$CONFIG['DB']['SCHEMA'].'affiliate AS a ON a.id_affiliate = wt.id_affiliate 
ORDER BY id_working_truck
', array());

                echo json_encode($data);
                break;

            case 'combine-to-truck':
                $data = db_query(1, '
                SELECT 
uctt.*, 
t.state_number_truck AS state_number_truck, 
t.serial_number_truck AS serial_number_truck, 
t.department_truck AS department_truck, 
c.state_number_combine AS state_number_combine, 
c.serial_number_combine AS serial_number_combine, 
c.department_combine AS department_combine, 
f.id_field AS id_field, 
a.name_affiliate AS name_affiliate, 
a.adress_affiliate AS adress_affiliate, 
a.phone_number AS phone_number_affiliate 
FROM '.$CONFIG['DB']['SCHEMA'].'unloading_combine_to_truck AS uctt 
JOIN '.$CONFIG['DB']['SCHEMA'].'truck AS t ON t.id_truck = uctt.id_working_truck 
JOIN '.$CONFIG['DB']['SCHEMA'].'combine AS c ON c.id_combine = uctt.id_working_combine 
JOIN '.$CONFIG['DB']['SCHEMA'].'field AS f ON f.id_field = uctt.id_field 
JOIN '.$CONFIG['DB']['SCHEMA'].'affiliate AS a ON a.id_affiliate = uctt.id_affiliate 
', array());

                echo json_encode($data);
                break;

            case 'truck-to-elevator':
               $data = db_query(1, '
                SELECT 
utte.*, 
t.state_number_truck AS state_number_truck, 
t.serial_number_truck AS serial_number_truck, 
t.department_truck AS department_truck, 
e.adress_elevator AS adress_elevator, 
f.id_field AS id_field, 
a.name_affiliate AS name_affiliate, 
a.adress_affiliate AS adress_affiliate, 
a.phone_number AS phone_number_affiliate 
FROM '.$CONFIG['DB']['SCHEMA'].'unloading_truck_to_elevator AS utte 
JOIN '.$CONFIG['DB']['SCHEMA'].'truck AS t ON t.id_truck = utte.id_working_truck 
JOIN '.$CONFIG['DB']['SCHEMA'].'elevator AS e ON e.id_elevator = utte.id_elevator 
JOIN '.$CONFIG['DB']['SCHEMA'].'field AS f ON f.id_field = utte.id_field 
JOIN '.$CONFIG['DB']['SCHEMA'].'affiliate AS a ON a.id_affiliate = utte.id_affiliate 
', array());

                echo json_encode($data);
                break;
                
            case 'geo':
                $data = db_query(1, '
SELECT 
wc.*, 
c.state_number_combine AS state_number_combine, 
c.serial_number_combine AS serial_number_combine, 
c.department_combine AS department_combine, 
e.name_employee AS name_employee, 
e.surname_employee AS surname_employee, 
e.position_employee AS position_employee, 
e.phone_number_employee AS phone_number_employee, 
a.name_affiliate AS name_affiliate, 
a.adress_affiliate AS adress_affiliate, 
a.phone_number AS phone_number_affiliate 
FROM '.$CONFIG['DB']['SCHEMA'].'working_combine AS wc 
JOIN '.$CONFIG['DB']['SCHEMA'].'combine AS c ON c.id_combine = wc.id_combine
JOIN '.$CONFIG['DB']['SCHEMA'].'employee AS e ON e.id_employee = wc.id_employee 
JOIN '.$CONFIG['DB']['SCHEMA'].'affiliate AS a ON a.id_affiliate = wc.id_affiliate
', array());
                $data2 = db_query(1, '
                SELECT 
wt.*, 
t.state_number_truck AS state_number_truck, 
t.serial_number_truck AS serial_number_truck, 
t.department_truck AS department_truck, 
e.name_employee AS name_employee, 
e.surname_employee AS surname_employee, 
e.position_employee AS position_employee, 
e.phone_number_employee AS phone_number_employee, 
a.name_affiliate AS name_affiliate, 
a.adress_affiliate AS adress_affiliate, 
a.phone_number AS phone_number_affiliate 
FROM '.$CONFIG['DB']['SCHEMA'].'working_truck AS wt 
JOIN '.$CONFIG['DB']['SCHEMA'].'truck AS t ON t.id_truck = wt.id_truck
JOIN '.$CONFIG['DB']['SCHEMA'].'employee AS e ON e.id_employee = wt.id_employee 
JOIN '.$CONFIG['DB']['SCHEMA'].'affiliate AS a ON a.id_affiliate = wt.id_affiliate
                ', array());

                echo json_encode(array_merge($data, $data2));
                break;

            case 'incidents':
                if(!isset($_GET['start'])){
                    $_GET['start'] = date('Y-m-d');
                }else{
                    $_GET['start'] = urldecode($_GET['start']);
                }

                if(!isset($_GET['end'])){
                    $_GET['end'] = date('Y-m-d', time()+86400+86400);
                }else{
                    $_GET['end'] = date('Y-m-d', strtotime(urldecode($_GET['end']))+86400);
                }

                $data = db_query(1, '
                SELECT 
i.*, 
t.state_number_truck AS state_number_truck, 
t.serial_number_truck AS serial_number_truck, 
c.state_number_combine AS state_number_combine, 
c.serial_number_combine AS serial_number_combine, 
e.name_employee AS name_employee, 
e.surname_employee AS surname_employee, 
e.position_employee AS position_employee, 
e.phone_number_employee AS phone_number_employee, 
a.name_affiliate AS name_affiliate, 
a.adress_affiliate AS adress_affiliate, 
a.phone_number AS phone_number_affiliate 
FROM '.$CONFIG['DB']['SCHEMA'].'incident AS i 
JOIN '.$CONFIG['DB']['SCHEMA'].'truck AS t ON t.id_truck = i.id_truck 
JOIN '.$CONFIG['DB']['SCHEMA'].'combine AS c ON c.id_combine = i.id_combine 
JOIN '.$CONFIG['DB']['SCHEMA'].'employee AS e ON e.id_employee = i.id_employee 
JOIN '.$CONFIG['DB']['SCHEMA'].'affiliate AS a ON a.id_affiliate = i.id_affiliate 
WHERE i.datetime_incident >= ? AND i.datetime_incident <= ?
', array($_GET['start'], $_GET['end']));

                echo json_encode($data);
                break;

            default:
                echo json_encode(array('no data'));
                break;
        }

        exit();
    }

    switch (@$_GET['page']) {
        case 'geo':
            include 'view/header.inc';
            include 'view/geo.inc';
            include 'view/footer.inc';
            break;

        case 'accidents':
            include 'view/header.inc';
            include 'view/accidents.inc';
            include 'view/footer.inc';
            break;

        default:
            include 'view/header.inc';
            include 'view/main.inc';
            include 'view/footer.inc';
            break;
    }
}else{
    if(isset($_POST['login'])){
        if(auth($_POST['login'], $_POST['password'])){
            $_SESSION['AUTH'] = true;
            header('Location: /');
            exit();
        }else{
            $ERROR['STATUS'] = 'danger';
            $ERROR['INFO'] = 'Введено невiрнi даннi!';
        }
    }

    include 'view/header.inc';
    include 'view/auth.inc';
    include 'view/footer.inc';
}