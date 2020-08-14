<!doctype html>
<html lang="ua">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <title>Zerno</title>

    <link rel="stylesheet" href="/assets/css/bootstrap.min.css">
    <link rel="stylesheet" href="/assets/css/font-awesome.min.css">

    <script src="/assets/js/jquery-3.3.1.min.js"></script>
    <script src="/assets/js/popper.min.js"></script>
    <script src="/assets/js/bootstrap.min.js"></script>
    <script src="/assets/js/jszip.min.js"></script>
    <script src="/assets/js/FileSaver.min.js"></script>
    <script src="/assets/js/excel-gen.js"></script>
    <script src="/assets/js/custom.js"></script>
</head>
<body>

<?php if(isset($ERROR)): ?>
<div class="alert alert-<?=$ERROR['STATUS']?> rounded-0">
    <div class="container">
        <h4>
            <strong><?=$ERROR['INFO']?></strong>
        </h4>
    </div>
</div>
<?php endif; ?>