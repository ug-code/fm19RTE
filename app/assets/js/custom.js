<!-- END THEME LAYOUT SCRIPTS -->
jQuery(document).ready(function () {
// Floating labels
    var handleInput = function (el) {
        if (el.val() != "") {
            el.addClass('edited');
        } else {
            el.removeClass('edited');
        }
    }

    $(document.body).on('keydown', '.form-md-floating-label .form-control', function (e) {
        handleInput($(this));
    });
    $(document.body).on('blur', '.form-md-floating-label .form-control', function (e) {
        handleInput($(this));
    });
    $(document.body).on('change', '.form-md-floating-label .form-control', function (e) {
        handleInput($(this));
    });

    $('.form-md-floating-label .form-control').each(function () {
        if ($(this).val().length > 0) {
            $(this).addClass('edited');
        }
    });

});