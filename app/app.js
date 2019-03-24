'use strict';

const env   = {
    production: 'dev'
};
const myApp = angular.module('myApp', [
    'ngRoute'
]);


myApp.factory('HelperService', function () {
    return {
        getColor: function (val) {
            let colorClass;
            if (val === 100) {
                colorClass = 'text-success';
            }
            else if (60 <= val && val < 100) {
                colorClass = 'text-success';
            }
            else if (40 <= val && val < 60) {
                colorClass = 'text-secondary';
            }
            else if (20 <= val && val < 40) {
                colorClass = 'text-secondary';
            }
            else if (1 <= val && val < 20) {
                colorClass = 'text-danger';
            }
            else if (val === 0) {
                colorClass = 'text-danger';
            }
            console.log("colorClass", colorClass);
            return colorClass;

        }
    };
});


/**----------Routing----------**/
myApp.config(['$locationProvider', '$routeProvider', function ($locationProvider, $routeProvider) {
    $locationProvider.hashPrefix('!');

    $routeProvider.when('/', {
        title: 'Home',
        templateUrl: 'view/home/home.html',
        //controller: 'HomeController'
    });

    $routeProvider.when('/player', {
        title: 'Player',
        templateUrl: 'view/player/player-list.html',
        controller: 'PlayerListController'

    });

    $routeProvider.when('/club', {
        title: 'Club',
        templateUrl: 'view/club/club-list.html',
        controller: 'ClubListController'

    });

    $routeProvider.when('/player/:id', {
        title: 'Player Detail',
        templateUrl: 'view/player/player.html',
        controller: 'PlayerController'

    });

    $routeProvider.when('/myProfile', {
        title: 'My Profile',
        templateUrl: 'view/staff/myProfile.html',
        controller: 'MyProfileController'

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
        controller: 'HeaderController'
    };
});


//listener.

myApp.directive('colorValue', function (HelperService) {
    return {
        link: Link
    };

    function Link(scope, elem, attrs) {

        scope.$watch(attrs.ngModel, function (v) {
            if (v && v !== null) {
                console.log("value", v);
                elem.addClass(HelperService.getColor(v));

            }
        });


    }
});
/**----------HeaderController----------**/
myApp.controller('HeaderController', ['$scope', '$http', '$q', '$timeout', function ($scope, $http, $q, $timeout) {

    $scope.getLoad = function () {


        $http.get('api/service/fmLoader').then(successCallback, errorCallback);

        function successCallback(response) {
            console.log("response", response.data);
        }

        function errorCallback(error) {
            console.log("error", error.status);
        }

    };


}]);

/**----------PlayerListController----------**/
myApp.controller('PlayerListController', ['$scope', '$location', '$http', '$q', '$timeout', function ($scope, $location, $http, $q, $timeout) {


    angular.element(document).ready(function () {
        const dtEl   = '#player_table';
        const dtable = $(dtEl).DataTable({
            "processing": true,
            responsive: true,
            "ajax": 'assets/json/playerdt.json',
            "deferRender": true,
            "columns": [
                {"data": "playerUniqueID"},
                {"data": "getFullname"},
                {"data": "getCA"},
                {"data": "getPA"},
                {"data": "getClubUniqueID"},
                {"data": "getClubName"},
                {"data": "getValue", render: $.fn.dataTable.render.number(',', '.')},

            ],
            rowId: 'playerUniqueID'
        });


        $(dtEl + ' tbody').on('click', 'tr', function () {
            var id = dtable.row(this).id();
            console.log("id", id);
            $scope.$apply(function () {
                $location.path('/player/' + id);
            });
            //console.log( 'You clicked on '+data[0]+'\'s row' );
        });


    });

}]);


/**----------ClubListController----------**/
myApp.controller('ClubListController', ['$scope', '$location', '$http', '$q', '$timeout', function ($scope, $location, $http, $q, $timeout) {


    angular.element(document).ready(function () {
        const dtEl   = '#club_table';
        const dtable = $(dtEl).DataTable({
            "processing": true,
            responsive: true,
            "ajax": 'assets/json/clubdt.json',
            "deferRender": true,
            "columns": [
                {"data": "getClubUniqueID"},
                {"data": "getFullname"},

            ],
            rowId: 'getClubUniqueID'
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

/**----------MyProfileController----------**/
myApp.controller('MyProfileController', ['$scope', '$http', '$q', '$timeout', function ($scope, $http, $q, $timeout) {

    $http.get('api/service/myProfile').then(successCallback, errorCallback);

    function successCallback(response) {
        console.log("response", response.data);
        $scope.myProfile = response.data;
    }

    function errorCallback(error) {
        if (env.production === 'dev' && error.status === 404) {
            console.log("Fake Data?");
        }

        console.log("error", error.status);

    }

}]);


/**----------PlayerController----------**/
myApp.controller('PlayerController', ['$scope', '$http', '$routeParams', 'HelperService', function ($scope, $http, $routeParams, HelperService) {

    const param = $routeParams.id;
    console.log("PlayerController param", param);

    $scope.getColor = function (val) {
        console.log("val", val);
        return HelperService.getColor(val);
    };


    $http.get('api/service/player/' + param).then(successCallback, errorCallback);

    function successCallback(response) {
        console.log("response", response.data);
        $scope.player = response.data;
    }

    function errorCallback(error) {
        if (env.production === 'dev' && error.status === 404) {
            $http.get('assets/json/player-details/fake-player.json').then(function (response) {
                $scope.player = response.data;
            });
        }
        console.log("error", error.status);

    }

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
