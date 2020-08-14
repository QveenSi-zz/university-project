<div class="container mt-5">
    <div class="row">
        <div class="col-md-3">
            <?php include 'view/nav.inc'; ?>
        </div>
        <div class="col-md-9">
            <p class="text-dark text-uppercase mb-0">Пошук по датi</p>
            <div class="jumbotron py-2 px-4 m-0">
                <form class="form-inline justify-content-end">
                    <div class="form-group">
                        <label for="start">Починаючи з&ensp;</label>
                        <input type="date" name="start" class="form-control" id="start" value="<?=date('Y-m-d')?>">
                    </div>
                    <div class="form-group mx-sm-3">
                        <label for="end">по&ensp;</label>
                        <input type="date" name="end" class="form-control" id="end" value="<?=date('Y-m-d', time()+86400)?>">
                    </div>
                    <button type="button" class="btn btn-dark text-uppercase font-weight-light" id="update"><i class="fa fa-search mr-2"></i>Знайти</button>
                </form>
            </div>

            <p class="text-right mt-2">
                <button type="button" class="btn btn-outline-success btn-sm export_xls" data-target="table" data-name="Iнциденти">Експортувати у Excel</button>
            </p>
            <table class="table table-striped table-hover shadow-sm mt-4">
                <thead class="bg-dark text-warning">
                <tr>
                    <th scope="col">Тип</th>
                    <th scope="col"><small>к-сть (тонн)</small><br>Розмiр</th>
                    <th scope="col">Час</th>
                    <th scope="col">Координати</th>
                    <th scope="col">Номер</th>
                    <th scope="col">Робiтник</th>
                    <th scope="col">Вiддiл</th>
                </tr>
                </thead>
                <tbody>

                </tbody>
            </table>
        </div>
    </div>
</div>

<script>
    $(function(){
        function updateData(){
            $.getJSON( '/?get=incidents&start='+$('#start').val()+'&end='+$('#end').val(), function( data ) {
                var table = $('table tbody');
                var newData = '';

                $.each( data, function( key, val ) {
                    newData += '<tr>';
                    newData += '<td>'+(val.type_incident > 1 ? "Вантажiвка" : "Комбайн")+'</td>';
                    newData += '<td>'+val.shortage+'</td>';
                    newData += '<td>'+val.datetime_incident.replace(/\-/g, '.')+'</td>';
                    newData += '<td>'+val.coordinates_incident.split(',')[0]+'<br>'+val.coordinates_incident.split(',')[1]+'</td>';
                    newData += '<td>'+(val.type_incident > 1 ? val.state_number_truck : val.state_number_combine)+'</td>';
                    newData += '<td>'+val.name_employee+' '+val.surname_employee+'<br>'+val.position_employee+'<br>'+val.phone_number_employee+'</td>';
                    newData += '<td>'+val.name_affiliate+'<br>'+val.adress_affiliate+'<br>'+val.phone_number_affiliate+'</td>';
                    newData += '</tr>';
                });

                $(table).html(newData);
            });
        }

        updateData();

        setInterval(function(){
            updateData();
        }, 10000);

        $('#update').click(function(){
            updateData();
        });
    });
</script>