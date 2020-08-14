<div class="container mt-5">
    <div class="row">
        <div class="col-md-2">
            <?php include 'view/nav.inc'; ?>
        </div>
        <div class="col-md-10">
            <ul class="nav nav-pills" id="categoryTab" role="tablist">
                <li class="nav-item">
                    <a class="nav-link active" id="employee-tab" data-toggle="tab" href="#employee" role="tab" aria-controls="employee" aria-selected="true">
                        Робiтники
                    </a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" id="trucks-tab" data-toggle="tab" href="#trucks" role="tab" aria-controls="trucks" aria-selected="true">
                        Вантажiвки
                    </a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" id="combines-tab" data-toggle="tab" href="#combines" role="tab" aria-controls="combines" aria-selected="true">
                        Комбайни
                    </a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" id="elevators-tab" data-toggle="tab" href="#elevators" role="tab" aria-controls="elevators" aria-selected="true">
                        Елеватори
                    </a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" id="combines-active-tab" data-toggle="tab" href="#combines-active" role="tab" aria-controls="combines-active" aria-selected="true">
                        Комбайны в роботi
                    </a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" id="trucks-active-tab" data-toggle="tab" href="#trucks-active" role="tab" aria-controls="trucks-active" aria-selected="true">
                        Вантажiвки в роботi
                    </a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" id="combine-to-truck-tab" data-toggle="tab" href="#combine-to-truck" role="tab" aria-controls="combine-to-truck" aria-selected="true">
                        Розвант. комб. - ван.
                    </a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" id="truck-to-elevator-tab" data-toggle="tab" href="#truck-to-elevator" role="tab" aria-controls="truck-to-elevator" aria-selected="true">
                        Розвант. ван. - елеват.
                    </a>
                </li>
            </ul>

            <div class="tab-content">
                <div class="tab-pane active" id="employee" role="tabpanel" aria-labelledby="employee-tab">
                    <p class="text-right">
                        <button type="button" class="btn btn-outline-success btn-sm export_xls" data-target="#employee table" data-name="Робiтники">Експортувати у Excel</button>
                    </p>
                    <table class="table table-striped table-hover shadow-sm">
                        <thead class="bg-dark text-warning">
                        <tr>
                            <th scope="col">Iм'я</th>
                            <th scope="col">Прiзвище</th>
                            <th scope="col">Позицiя</th>
                            <th scope="col">Телефон</th>
                        </tr>
                        </thead>
                        <tbody>

                        </tbody>
                    </table>
                </div>
                <div class="tab-pane" id="trucks" role="tabpanel" aria-labelledby="trucks-tab">
                    <p class="text-right">
                        <button type="button" class="btn btn-outline-success btn-sm export_xls" data-target="#trucks table" data-name="Вантажiвки">Експортувати у Excel</button>
                    </p>
                    <table class="table table-striped table-hover shadow-sm">
                        <thead class="bg-dark text-warning">
                        <tr>
                            <th scope="col">Номер</th>
                            <th scope="col">Серiйний номер</th>
                            <th scope="col">Рiк випуску</th>
                            <th scope="col">Гарантiя</th>
                            <th scope="col"><small>к-сть (тонн)</small><br>Вантажопiдйомнiсть</th>
                        </tr>
                        </thead>
                        <tbody>

                        </tbody>
                    </table>
                </div>
                <div class="tab-pane" id="combines" role="tabpanel" aria-labelledby="combines-tab">
                    <p class="text-right">
                        <button type="button" class="btn btn-outline-success btn-sm export_xls" data-target="#combines table" data-name="Комбайни">Експортувати у Excel</button>
                    </p>
                    <table class="table table-striped table-hover shadow-sm">
                        <thead class="bg-dark text-warning">
                        <tr>
                            <th scope="col">Номер</th>
                            <th scope="col">Серiйний номер</th>
                            <th scope="col">Рiк випуску</th>
                            <th scope="col">Гарантiя</th>
                            <th scope="col"><small>к-сть (тонн)</small><br>Вантажопiдйомнiсть</th>
                        </tr>
                        </thead>
                        <tbody>

                        </tbody>
                    </table>
                </div>
                <div class="tab-pane" id="elevators" role="tabpanel" aria-labelledby="elevators-tab">
                    <p class="text-right">
                        <button type="button" class="btn btn-outline-success btn-sm export_xls" data-target="#elevators table" data-name="Елеватори">Експортувати у Excel</button>
                    </p>
                    <table class="table table-striped table-hover shadow-sm">
                        <thead class="bg-dark text-warning">
                        <tr>
                            <th scope="col">Адреса</th>
                            <th scope="col"><small>к-сть (тонн)</small><br>Об'єм</th>
                            <th scope="col"><small>к-сть (тонн)</small><br>Заповнено</th>
                        </tr>
                        </thead>
                        <tbody>

                        </tbody>
                    </table>
                </div>
                <div class="tab-pane" id="combines-active" role="tabpanel" aria-labelledby="combines-active-tab">
                    <p class="text-right">
                        <button type="button" class="btn btn-outline-success btn-sm export_xls" data-target="#combines-active table" data-name="Комбайни у роботi">Експортувати у Excel</button>
                    </p>
                    <table class="table table-striped table-hover shadow-sm">
                        <thead class="bg-dark text-warning">
                        <tr>
                            <th scope="col"><small>к-сть (тонн)</small><br>Заповнено</th>
                            <th scope="col">Координати</th>
                            <th scope="col">Робiтник</th>
                            <th scope="col">Вiддiл</th>
                            <th scope="col">Комбайн</th>
                        </tr>
                        </thead>
                        <tbody>

                        </tbody>
                    </table>
                </div>
                <div class="tab-pane" id="trucks-active" role="tabpanel" aria-labelledby="trucks-active-tab">
                    <p class="text-right">
                        <button type="button" class="btn btn-outline-success btn-sm export_xls" data-target="#truck-active table" data-name="Вантажiвки у роботi">Експортувати у Excel</button>
                    </p>
                    <table class="table table-striped table-hover shadow-sm">
                        <thead class="bg-dark text-warning">
                        <tr>
                            <th scope="col"><small>к-сть (тонн)</small><br>Заповнено</th>
                            <th scope="col">Координати</th>
                            <th scope="col">Робiтник</th>
                            <th scope="col">Вiддiл</th>
                            <th scope="col">Комбайн</th>
                        </tr>
                        </thead>
                        <tbody>

                        </tbody>
                    </table>
                </div>
                <div class="tab-pane" id="combine-to-truck" role="tabpanel" aria-labelledby="combine-to-truck-tab">
                    <p class="text-right">
                        <button type="button" class="btn btn-outline-success btn-sm export_xls" data-target="#combine-to-truck table" data-name="З комбайна у вантажiвку">Експортувати у Excel</button>
                    </p>
                    <table class="table table-striped table-hover shadow-sm">
                        <thead class="bg-dark text-warning">
                        <tr>
                            <th scope="col">Дата</th>
                            <th scope="col"><small>к-сть (тонн)</small><br>Розмiр</th>
                            <th scope="col">Вантажiвка</th>
                            <th scope="col">Комбайн</th>
                            <th scope="col">Вiддiл</th>
                        </tr>
                        </thead>
                        <tbody>

                        </tbody>
                    </table>
                </div>
                <div class="tab-pane" id="truck-to-elevator" role="tabpanel" aria-labelledby="truck-to-elevator-tab">
                    <p class="text-right">
                        <button type="button" class="btn btn-outline-success btn-sm export_xls" data-target="#truck-to-elevator table" data-name="З вантажiвки у елеватор">Експортувати у Excel</button>
                    </p>
                    <table class="table table-striped table-hover shadow-sm">
                        <thead class="bg-dark text-warning">
                        <tr>
                            <th scope="col">Дата</th>
                            <th scope="col"><small>к-сть (тонн)</small><br>Розмiр</th>
                            <th scope="col">Вантажiвка</th>
                            <th scope="col">Елеватор</th>
                            <th scope="col">Вiддiл</th>
                        </tr>
                        </thead>
                        <tbody>

                        </tbody>
                    </table>
                </div>
            </div>
        </div>
    </div>
</div>

<script>
    $(function(){
        $('#categoryTab a[data-toggle="tab"]').on('shown.bs.tab', function (e) {
            updateData($(this).attr('id'));
        });

        function updateData(type){
            switch(type){
                case 'trucks-tab':
                    $.getJSON( '/?get=trucks', function( data ) {
                        var currentTab = $('#trucks table tbody');
                        var newData = '';

                        $.each( data, function( key, val ) {
                            newData += '<tr>';
                            newData += '<td>'+val.state_number_truck+'</td>';
                            newData += '<td>'+val.serial_number_truck+'</td>';
                            newData += '<td>'+val.graduation_year_truck+'</td>';
                            newData +='<td>'+val.warranty_period_truck+'</td>';
                            newData +='<td>'+val.department_truck+'</td>';
                            newData +='</tr>';
                        });

                        $(currentTab).html(newData);
                    });
                    break;

                case 'combines-tab':
                    $.getJSON( '/?get=combines', function( data ) {
                        var currentTab = $('#combines table tbody');
                        var newData = '';

                        $.each( data, function( key, val ) {
                            newData +='<tr>';
                            newData +='<td>'+val.state_number_combine+'</td>';
                            newData +='<td>'+val.serial_number_combine+'</td>';
                            newData +='<td>'+val.graduation_year_combine+'</td>';
                            newData +='<td>'+val.warranty_period_combine+'</td>';
                            newData +='<td>'+val.department_combine+'</td>';
                            newData +='</tr>';
                        });

                        $(currentTab).html(newData);
                    });
                    break;

                case 'elevators-tab':
                    $.getJSON( '/?get=elevators', function( data ) {
                        var currentTab = $('#elevators table tbody');
                        var newData = '';

                        $.each( data, function( key, val ) {
                           newData +='<tr>';
                           newData +='<td>'+val.adress_elevator+'</td>';
                           newData +='<td>'+val.volume_elevator+'</td>';
                           newData +='<td>'+val.current_volume_elevator+'</td>';
                           newData +='</tr>';
                        });

                        $(currentTab).html(newData);
                    });
                    break;

                case 'combines-active-tab':
                    $.getJSON( '/?get=combines-active', function( data ) {
                        var currentTab = $('#combines-active table tbody');
                        var newData = '';

                        $.each( data, function( key, val ) {
                           newData +='<tr>';
                           newData +='<td>'+val.current_depatment_combine+'</td>';
                           newData +='<td>'+val.coordinates_combine+'</td>';
                           newData +='<td>'+val.name_employee+' '+val.surname_employee+' ('+val.position_employee+')</td>';
                           newData +='<td>'+val.name_affiliate+'</td>';
                           newData +='<td>'+val.state_number_combine+'</td>';
                           newData +='</tr>';
                        });

                        $(currentTab).html(newData);
                    });
                    break;

                case 'trucks-active-tab':
                    $.getJSON( '/?get=trucks-active', function( data ) {
                        var currentTab = $('#trucks-active table tbody');
                        var newData = '';

                        $.each( data, function( key, val ) {
                           newData +='<tr>';
                           newData +='<td>'+val.current_department_truck+'</td>';
                           newData +='<td>'+val.coordinates_truck+'</td>';
                           newData +='<td>'+val.name_employee+' '+val.surname_employee+' ('+val.position_employee+')</td>';
                           newData +='<td>'+val.name_affiliate+'</td>';
                           newData +='<td>'+val.state_number_truck+'</td>';
                           newData +='</tr>';
                        });

                        $(currentTab).html(newData);
                    });
                    break;

                case 'combine-to-truck-tab':
                    $.getJSON( '/?get=combine-to-truck', function( data ) {
                        var currentTab = $('#combine-to-truck table tbody');
                        var newData = '';

                        $.each( data, function( key, val ) {
                           newData +='<tr>';
                           newData +='<td>'+val.datetime_unloading_combine_to_+'</td>';
                           newData +='<td>'+val.size_combine_to_truck+'</td>';
                           newData +='<td>'+val.state_number_truck+'</td>';
                           newData +='<td>'+val.state_number_combine+'</td>';
                           newData +='<td>'+val.name_affiliate+'</td>';
                           newData +='</tr>';
                        });

                        $(currentTab).html(newData);
                    });
                    break;

                case 'truck-to-elevator-tab':
                    $.getJSON( '/?get=truck-to-elevator', function( data ) {
                        var currentTab = $('#truck-to-elevator table tbody');
                        var newData = '';

                        $.each( data, function( key, val ) {
                           newData +='<tr>';
                           newData +='<td>'+val.datetime_unloading_truck_to_el+'</td>';
                           newData +='<td>'+val.size_truck_to_elevator+'</td>';
                           newData +='<td>'+val.state_number_truck+'</td>';
                           newData +='<td>'+val.adress_elevator+'</td>';
                           newData +='<td>'+val.name_affiliate+'</td>';
                           newData +='</tr>';
                        });

                        $(currentTab).html(newData);
                    });
                    break;

                default:
                    $.getJSON( '/?get=employee', function( data ) {
                        var currentTab = $('#employee table tbody');
                        var newData = '';

                        $.each( data, function( key, val ) {
                           newData +='<tr>';
                           newData +='<td>'+val.name_employee+'</td>';
                           newData +='<td>'+val.surname_employee+'</td>';
                           newData +='<td>'+val.position_employee+'</td>';
                           newData +='<td>'+val.phone_number_employee+'</td>';
                           newData +='</tr>';
                        });

                        $(currentTab).html(newData);
                    });
                    break;
            }
        }

        updateData('employee-tab');

        setInterval(function(){
            updateData($('#categoryTab a[data-toggle="tab"].active').attr('id'));
        }, 10000);
    });
</script>