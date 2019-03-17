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

/**----------PlayerListController----------**/
myApp.controller('PlayerListController', ['$scope', '$http', '$q', '$timeout', function ($scope, $http, $q, $timeout) {

    $scope.users = [
        {
            email: 'email@address.com',
            name: {
                first: 'User',
                last: 'Last Name'
            },
            phone: '(416) 555-5555',
            permissions: 'Admin'
        },
        {
            email: 'example@email.com',
            name: {
                first: 'First',
                last: 'Last'
            },
            phone: '(514) 222-1111',
            permissions: 'User'
        }
    ];

    angular.element(document).ready(function () {
        const dTable = $('#player_table');
        dTable.DataTable({
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

            ]
        });
    });

}]);

/**----------MyClubController----------**/
myApp.controller('MyClubController', ['$scope', '$http', '$q', '$timeout', function ($scope, $http, $q, $timeout) {

    $http.get('api/service/currentClub').then(function (response) {
        console.log("response", response.data);
        $scope.myClub = response.data;
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
