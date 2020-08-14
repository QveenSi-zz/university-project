$(function(){
    function checkIncidents(){
        var dt = new Date();
        dt.setSeconds(dt.getSeconds() - 30);
        var time = dt.getFullYear() + "-" + (parseInt(dt.getMonth())+1) + "-" + dt.getDate() + " "+dt.getHours() + ":" + dt.getMinutes() + ":" + (dt.getSeconds());
        console.log(time);
        $.getJSON( '/?get=incidents&start='+encodeURIComponent(time), function( data ) {
            console.log(data);
            $.each( data, function( key, val ) {
                if(!$('#incident-'+val.id_incident).length){
                    console.log('New incident!');

                    beep();

                    $('body').prepend('<div class="alert alert-danger alert-dismissible fade show rounded-0 mb-0" id="incident-' + val.id_incident + '">' +
                        '    <div class="container">' +
                        '<a href="/?page=incidents&start=' + encodeURIComponent(time) + '" class="btn btn-danger btn-sm text-uppercase float-right">Переглянути</a>' +
                        '        <h6>' +
                        '            <strong>Iнцидент! Тип: ' + (val.type_incident > 1 ? "Вантажiвка" : "Комбайн") + ', розмiр: ' + val.shortage + 'т</strong>' +
                        '        </h6>' +
                        '    </div>' +
                        '<button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>' +
                        '</div>');
                }else{
                    console.log('old');
                }
            });
        });
    }

    function beep(){
        var snd = new Audio('/assets/audio/alarm.mp3');
        snd.volume = 1;

        snd.addEventListener('ended',function(){
            this.pause();
            this.currentTime = 0;
        });

        snd.play();
    }

    //checkIncidents();

    setInterval(function(){
        checkIncidents();
    }, 10000);

    $('.export_xls').click(function(){
        var excel = new ExcelGen({
            "src": $($(this).data('target')),
            "show_header": true,
            "file_name": $(this).data('name')+".xlsx",
            "type": "table"
        });
        excel.generate();
    });

});