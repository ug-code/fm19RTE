'use strict';

const myApp = angular.module('myApp', [
    'ngRoute'
]);

/**----------Routing----------**/
myApp.config(['$locationProvider', '$routeProvider', function ($locationProvider, $routeProvider) {
    $locationProvider.hashPrefix('!');

    $routeProvider.when('/', {
        title: 'Home',
        templateUrl: 'view/home/home.html',
        //controller: 'HomeController'
    });

    $routeProvider.when('/player', {
        title: 'otherView',
        templateUrl: 'view/player/player-list.html',
        controller: 'PlayerListController'

    });

    $routeProvider.when('/player/:id', {
        title: 'otherView',
        templateUrl: 'view/player/player.html',
        controller: 'PlayerController'

    });

    $routeProvider.when('/myProfile', {
        title: 'otherView',
        templateUrl: 'view/staff/myProfile.html',
        //controller: 'PlayerController'

    });

    $routeProvider.when('/myClub', {
        title: 'otherView',
        templateUrl: 'view/club/myClub.html',
        controller: "MyClubController"

    });

    $routeProvider.otherwise({redirectTo: '/'});
}]);

/**----------appFooter----------**/
myApp.directive('appFooter', function () {
    return {
        restrict: 'E',
        replace: true,
        templateUrl: 'view/shared/footer/footer.html',
        controller: function () {
            this.date       = Date.now();
            this.dateFormat = 'yyyy'
        },
        controllerAs: 'footer'
    };
});

/**----------appHeader----------**/
myApp.directive('appHeader', function () {
    return {
        restrict: 'E',
        replace: true,
        templateUrl: 'view/shared/header/header.html',
    };
});


//listener.
/*
myApp.directive('input', function() {
        return {
            restrict: 'E',
            link: Link
        };

        function Link(scope, elem, attrs) {
            if(attrs.class==='md-input form-control'){

                scope.$watch(attrs.ngModel, function (v) {
                    if(v!==''){
                        elem.addClass('edited');
                    }
                });
                elem.on('focus', function() {
                    // do stuff
                    console.log(elem[0].name + ' has been focused!');
                });
            }
        }
    });
    */

/**----------PlayerListController----------**/
myApp.controller('PlayerListController', ['$scope','$location' ,'$http', '$q', '$timeout', function ($scope,$location, $http, $q, $timeout) {


    angular.element(document).ready(function () {
        const dtEl = '#player_table';
        const dtable =$(dtEl).DataTable({
            "processing": true,
            responsive: true,
            "ajax": 'assets/json/playerdt.json',
            "columns": [
                { "data": "playerUniqueID" },
                { "data": "getFullname" },
                { "data": "getCA" },
                { "data": "getPA" },
                { "data": "getClubUniqueID" },
                { "data": "getValue", render: $.fn.dataTable.render.number(',', '.') },

            ],
            rowId: 'playerUniqueID'
        });


        $(dtEl+' tbody').on('click', 'tr', function () {
            var id = dtable.row( this ).id();
            console.log("id",id);
            $scope.$apply(function() {
                $location.path('/player/' + id);
            });
            //console.log( 'You clicked on '+data[0]+'\'s row' );
        } );


    });

}]);

/**----------MyClubController----------**/
myApp.controller('MyClubController', ['$scope', '$http', '$q', '$timeout', function ($scope, $http, $q, $timeout) {

    $http.get('api/service/currentClub').then(function (response) {
        console.log("response", response.data);
        $scope.myClub = response.data;
    });

}]);

/**----------MyClubController----------**/
myApp.controller('PlayerController', ['$scope', '$http', '$routeParams', function ($scope, $http, $routeParams) {

    const param = $routeParams.id;
    console.log("PlayerController param",param);
    $http.get('api/service/player/'+param).then(function (response) {
        console.log("response", response.data);
        $scope.player = response.data;
    });

}]);


/**----------title----------**/
myApp.run(['$rootScope', function ($rootScope) {
    $rootScope.$on('$routeChangeSuccess', function (event, current, previous) {
        $rootScope.title = current.$$route.title;
    });
}]);

$('#myList a').on('click', function (e) {
    e.preventDefault();
    $(this).tab('show');
});
