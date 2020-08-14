<div class="container mt-5">
    <div class="row">
        <div class="col-md-2">
            <?php include 'view/nav.inc'; ?>
        </div>
        <div class="col-md-10">
            <div id="map" class="h-100 rounded shadow" style="min-height: 500px;"></div>
        </div>
    </div>
</div>

<script>
    function initMap() {
        var map = new google.maps.Map(document.getElementById('map'), {
            zoom: 12,
            center: {lat: 49.664211, lng: 30.949256},
            mapTypeId: 'satellite'
        });

        var infoWindow = new google.maps.InfoWindow();

        var content = '<div id="content">'+
            '<div id="siteNotice">'+
            '</div>'+
            '<h1 id="firstHeading" class="firstHeading">Uluru</h1>'+
            '<div id="bodyContent">'+
            '<p><b>Uluru</b>, also referred to as <b>Ayers Rock</b>, is a large ' +
            'sandstone rock formation in the southern part of the '+
            'Northern Territory, central Australia. It lies 335&#160;km (208&#160;mi) '+
            'south west of the nearest large town, Alice Springs; 450&#160;km '+
            '(280&#160;mi) by road. Kata Tjuta and Uluru are the two major '+
            'features of the Uluru - Kata Tjuta National Park. Uluru is '+
            'sacred to the Pitjantjatjara and Yankunytjatjara, the '+
            'Aboriginal people of the area. It has many springs, waterholes, '+
            'rock caves and ancient paintings. Uluru is listed as a World '+
            'Heritage Site.</p>'+
            '<p>Attribution: Uluru, <a href="https://en.wikipedia.org/w/index.php?title=Uluru&oldid=297882194">'+
            'https://en.wikipedia.org/w/index.php?title=Uluru</a> '+
            '(last visited June 22, 2009).</p>'+
            '</div>'+
            '</div>';

        function updateGeo(){
            $.getJSON( '/?get=geo', function( data ) {
                var markers = [];

                $.each( data, function( key, val ) {
                    var geo, label, info;

                    if(val.coordinates_combine) {
                        geo = val.coordinates_combine.split(',');
                        label = 'Комбайн '+val.state_number_combine;
                        
                        info = 'Комбайн номер: '+val.state_number_combine+'<br>';
                        info += 'Серiйний номер: '+val.serial_number_combine+'<br>';
                        info += 'Тонн: '+val.current_depatment_combine+' / '+val.department_combine+'<br>';
                        info += 'Координати: '+val.coordinates_combine+'<br>';
                        info += 'Робiтник: '+val.name_employee+' '+val.surname_employee+' ('+val.position_employee+', '+val.phone_number_employee+')'+'<br>';
                        info += 'Вiддiл: '+val.name_affiliate+'<br>';
                    }else{
                        geo = val.coordinates_truck.split(',');
                        label = 'Вантажiвка '+val.state_number_truck;
                        
                        info = 'Вантажiвка номер: '+val.state_number_truck+'<br>';
                        info += 'Серiйний номер: '+val.serial_number_truck+'<br>';
                        info += 'Тонн: '+val.current_department_truck+' / '+val.department_truck+'<br>';
                        info += 'Координати: '+val.coordinates_truck+'<br>';
                        info += 'Робiтник: '+val.name_employee+' '+val.surname_employee+' ('+val.position_employee+', '+val.phone_number_employee+')'+'<br>';
                        info += 'Вiддiл: '+val.name_affiliate+'<br>';
                    }

                    var lat = geo[0];
                    var lng = geo[1];

                    var marker = new google.maps.Marker({
                        position: new google.maps.LatLng(lat, lng),
                        label: label,
                        title: label,
                        map: map
                    });

                    google.maps.event.addListener(marker, 'click', function(event) {
                        infoWindow.setContent(info);
                        infoWindow.open(map, marker);
                    });

                    markers.push(marker);
                });

                var markerCluster = new MarkerClusterer(map, markers, {imagePath: 'https://developers.google.com/maps/documentation/javascript/examples/markerclusterer/m'});
            });
        }
        updateGeo();

        setInterval(function(){
            updateGeo();
        }, 10000);

        //var markerCluster = new MarkerClusterer(map, markers, {imagePath: 'https://developers.google.com/maps/documentation/javascript/examples/markerclusterer/m'});
    }
</script>
<script src="https://developers.google.com/maps/documentation/javascript/examples/markerclusterer/markerclusterer.js"></script>
<script async defer src="https://maps.googleapis.com/maps/api/js?key=AIzaSyBhKVzBrUWoAxqOLz933Cq_aMHZsw6CBt8&callback=initMap"></script>