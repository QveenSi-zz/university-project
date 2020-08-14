<nav class="nav nav-pills flex-column">
    <a class="nav-link<?=(!isset($_GET['page'])?' active':'')?>" href="/">
        Iнформативнi даннi
    </a>
    <a class="nav-link<?=(isset($_GET['page']) && $_GET['page'] == 'geo'?' active':'')?>" href="/?page=geo">
        Геоданнi
    </a>
    <a class="nav-link<?=(isset($_GET['page']) && $_GET['page'] == 'accidents'?' active':'')?>" href="/?page=accidents">
        Iнциденти
    </a>
</nav>