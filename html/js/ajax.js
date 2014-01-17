//PAGES

//Page2 (Team Eureka)

$(document).on('click', '#teameurekalink', function() {
$.scrollTo( {top:0, left:0}  );
$('#page').attr("class","page2");
$('#eureka').addClass("back");
});

$(document).on('click', '#eureka', function() {
$.scrollTo( {top:0, left:0}  );
$('#page').attr("class","page1");
$('#eureka').removeClass("back");
});


//SWIPE BETWEEN PAGES

//arrow keys

$(document).on('keydown','html',function(e) {

        if (e.which == 37)
        {
	    if ($('#page').is('.page2'))
		{$('#page').attr("class","page1"); $('#eureka').removeClass("back");}
        }
        if (e.which == 39)
        {
            if ($('#page').is('.page1'))
                {$('#page').attr("class","page2"); $('#eureka').addClass("back");}
        }

});



//SETTINGS

//Themes


//open DNS drawer
$(document).on('click', '#themesForm input:radio', function(e) {


var id = e.target.id;
    
if (id == 'candyland_theme') {
	    $('body').attr("class","candyland");
            }
if (id == 'metropolis_theme') {
	    $('body').attr("class","metropolis");
            }
if (id == 'bluescience_theme') {
	    $('body').attr("class","bluescience");
            }
if (id == 'cards_theme') {
	    $('body').attr("class","cards");
            }
if (id == 'ponytail_theme') {
            $('body').attr("class","ponytail");
            }
if (id == 'browncoats_theme') {
            $('body').attr("class","browncoats");
            }

                        


$(submitTheme);

});
        
function submitTheme(){

        $.ajax({
                type: 'POST',
                url: '?page=theme',
                cache: false,
                data: $('#themesForm').serialize(),
                beforeSend:function(){
                        // this is where we append a loading image
                },
                success:function(data){
                        // successful request; do something with the data
                        jQuery('li#settings_theme').empty();
                        jQuery('li#settings_theme').html(data);
                },
                error:function(){
                        // failed request; give feedback to user
                        jQuery('li#settings_theme').html('<p class="error"><strong>Oops!</strong> Try that again in a few moments.</p>');
                },
                complete:function(){
                }
        });


}




// hide bottom bar on scrolling and login focus
$(function() {

var mywindow = $(window);
var mypos = mywindow.scrollTop();
var up = false;
var newscroll;

mywindow.scroll(function () {
    newscroll = mywindow.scrollTop();
    if (newscroll > mypos && !up) {
	$('#bottom').addClass("mobilescroll");
        up = !up;
    } else if(newscroll < mypos && up) {
	$('#bottom').removeClass("mobilescroll");
        up = !up;
    }

    if($(window).scrollTop() + $(window).height() > $(document).height() - 40) {
       $('#bottom').removeClass("mobilescroll");
    }

    mypos = newscroll;
});

  $(document).on('focus', '#welcome_password', function(){
    $('#bottom').addClass("mobilescroll");
   });

   $(document).on('blur', '#welcome_password', function(){
    $('#bottom').removeClass("mobilescroll");
   });

});



//Check if cookie is still valid (or if a password is set at all) and try to load page

$(function() {
$('body').addClass("progress");


        $.ajax({
                type: 'GET',
                url: '?page=verify',
                async: false,
                cache: false,
                beforeSend:function(){
                        // this is where we append a loading image
                        jQuery('#welcome_login').empty();
                        jQuery('#welcome_login').html('<div id="welcome_load">Loading...</div>');
                },
                success:function(data){
                        // successful request; do something with the data
                        if(data == "Correct") {
                                $(loadCards);
                                } else {
                                jQuery('#welcome_login').empty();
                                jQuery('#welcome_login').html('<div id="welcome_pass"><input id="welcome_password" name="welcome_password" type="password"></div><div id="welcome_send" class="clickable">Log in</div>');
                                $('body').removeClass("progress");
				}
                },
                error:function(){
                        // failed request; give feedback to user
                        jQuery('#welcome_login').html('<strong>Oops!</strong> Try that again in a few moments.');
                },
                complete:function(){
                }
        });
});


//LOAD CARDS IN BACKGROUND

function loadCards(){
        $.ajax({
                type: 'GET',
                cache: false,
                url: '?page=cards&footers=0&headers=0',
                beforeSend:function(){
                        jQuery('#welcome_login').empty();
                        jQuery('#welcome_login').html('<div id="welcome_load">Loading...</div>');
                },
                success:function(data){
                        // successful request; do something with the data
                        jQuery('#slides').empty();
                        jQuery('#slides').html(data);
                },
                error:function(){
                        // failed request; give feedback to user
                        jQuery('#slides').html('<strong>Oops!</strong> Try that again in a few moments.');
                },
                complete:function(){
			setTimeout(function() {
				$('#welcome').addClass("login");
				jQuery('#welcome_send').html('Log in');
                                $('#welcome_send').addClass("clickable");
                                $('body').removeClass("progress");
                                $('#welcome_send').removeClass("wait");
                                $('#welcome_password').removeClass("wait");
                        //chrome hack (when scrolled to bottom before refresh, it cannot scroll up or down because stored scroll position and ajax
                                $(document.body).scrollTop("1");
                                $(document.body).scrollTop("0");
                                $('#logout').removeClass("hidden");
                                $('#settings').removeClass("hidden");
			},1500);
			setTimeout(function() {
                                jQuery('#welcome_login').empty();
                                jQuery('#welcome_login').html('<div id="welcome_pass"><input id="welcome_password" name="welcome_password" type="password"></div><div id="welcome_send" class="clickable">Log in</div>');
			},2500);
                }
        });

}


//LOGIN SEND
function submitLogin(){

// var form = $('#PanelLogin');
// var data = form.serialize();

        $.ajax({
                type: 'POST',
                cache: false,
                url: '?page=login',
                data: $('#PanelLogin').serialize(),
		async: false,
                beforeSend:function(){
                        // this is where we append a loading image
                        jQuery('#welcome_send').empty();
                        $('#welcome_send').removeClass("clickable");
			$('#welcome_password').addClass("disabled");
                        $('body').addClass("progress");
                        $('#welcome_send').addClass("wait");
                        $('#welcome_password').addClass("wait");
                        jQuery('#welcome_send').html('Checking');
                },
                success:function(data){
                        // successful request; do something with the data
                        if(data == "Correct") {
                        	$(loadCards); 
                        	} else {
                        	jQuery('#welcome_send').empty();
                        	jQuery('#welcome_send').html('Try again');
				$('#welcome_password').val(function() {return this.defaultValue;});
                        	$('#welcome_send').addClass("clickable");
                        	$('#welcome_password').removeClass("disabled");
                        	$('body').removeClass("progress");
                        	$('#welcome_send').removeClass("wait");
                        	$('#welcome_password').removeClass("wait");
                        	}
                },
                error:function(){
                        // failed request; give feedback to user
                        jQuery('#welcome_login').html('<strong>Oops!</strong> Try that again in a few moments.');
                },
                complete:function(){
                }
        });

}

//on submit (browser native enter key) - do nothing, do ajax on key 13 in special field only, not on not browser submit!
$(document).on('submit', '#PanelLogin', function() {

return false;

});

//onclick
$(document).on('click', '#welcome #welcome_login #welcome_send', function() {

	$(submitLogin);

});

//on enter

$(document).on('keypress','#welcome_pass #welcome_password',function(e) {

        if (e.which == 13)
        {
	$(submitLogin);
        }

});


//close DNS drawers anywhere outside of div #dns_update
$(document).on('focus click', 'body', function(e) {
    var target = $(e.target);  
    var id = e.target.id; 
    
    if (!target.parents('div#dns_update').length || id == 'CANCELcustomDNS') {
	$('#DNSselection').addClass("invisible");
	$('#DNScustom').removeClass("show");
    }
});
           
 

//open DNS drawer
$(document).on('click', '#DNSselected label', function() {

	$('#DNSselection').removeClass("invisible");
});


//CUSTOM DNS

function submitDNS(){

// var form = $('#customDNSform');
// var data = form.serialize();


        $.ajax({
                type: 'POST',
                url: '?page=dns',
                cache: false,
                data: $('#customDNSform').serialize(),
                beforeSend:function(){
                        // this is where we append a loading image
                        jQuery('#dns_update').empty();
                        jQuery('#dns_update').html('<div class="cbot"><div class="DNSloading">Updating...</div></div>');
                },
                success:function(data){
                        // successful request; do something with the data
                        jQuery('#dns_update').empty();
                        jQuery('#dns_update').html(data);
                },
                error:function(){
                        // failed request; give feedback to user
                        jQuery('#dns_update').html('<p class="error"><strong>Oops!</strong> Try that again in a few moments.</p>');
                },
                complete:function(){
                }
        });


}



//on submit (browser native enter key) - do nothing, do ajax on key 13 in special field only, not on not browser submit!
$(document).on('submit', '#customDNSform', function() {

return false;

});


// on click on send

$(document).on('click','#DNScustom #SENDcustomDNS',function(e) {

	$(submitDNS);

});

// on enter

$(document).on('keypress','#DNScustom #dns1field',function(e) {

	if (e.which == 13)
	{
	$('#dns2field').focus();
	}

});

$(document).on('keypress','#DNScustom #dns2field',function(e) {

         if (e.which == 13)
         {
         $(submitDNS);
         }

});

// SECURITY OPTIONS

// open drawer

//open DNS drawer
$(document).on('click', '#changePass label', function() {

	$('#Passcustom').addClass("show");

});


// on options click

// $(document).on('change', '#secureOptions input:checkbox', function() {
$(document).on('click', '#secureOptions #tickwebpanel', function() {
	$(changeSecOptions);
});
$(document).on('click', '#secureOptions #tickssh', function() {
        $(changeSecOptions);
});
$(document).on('click', '#secureOptions #makepassfirst', function() {
        $('#Passcustom').addClass("show");
});
     

function changeSecOptions(){

var webpanel = "false";
var ssh = "false";


if ($("#tickwebpanel").is(':checked'))
	{var webpanel = $("#tickwebpanel").val(); $('#logout').removeClass("invisible");$('#settings').addClass("logout");} else {$('#logout').addClass("invisible");$('#settings').removeClass("logout");}
if ($("#tickssh").is(':checked'))
        var ssh = $("#tickssh").val();
        

        $.ajax({
                type: 'POST',
                cache: false,
                url: '?page=security',
                data: { 'action': 'update', 'Security/webprotected': webpanel, 'Security/sshprotected': ssh },
                beforeSend:function(){
                        // this is where we append a loading image
                },
                success:function(data){
                        // successful request; do something with the data
                        jQuery('#security_update').empty();
                        jQuery('#security_update').html(data);
                },
                error:function(){
                        // failed request; give feedback to user
                        jQuery('#security_update').html('<p class="error"><strong>Oops!</strong> Try that again in a few moments.</p>');
                },
                complete:function(){
                }
        });

}

//SERVICES

function submitServices(){


        $.ajax({
                type: 'POST',
                cache: false,
                url: '?page=services',
                data: $('#servicesForm').serialize(),
                beforeSend:function(){
                        // this is where we append a loading image
                },
                success:function(data){
                        // successful request; do something with the data
                        if (data == "ikilledhttp") {
                        window.location.replace("?ikilledhttp");
                        }
                        else {
                        jQuery('#services_update').empty();
                        jQuery('#services_update').html(data);
                        }
                },
                error:function(){
                        // failed request; give feedback to user
                        jQuery('#services_update').html('<p class="error"><strong>Oops!</strong> Try that again in a few moments.</p>');
                },
                complete:function(){
                }
        });


}


//on submit (browser native enter key) - do nothing, do ajax on key 13 in special field only, not on not browser submit!
$(document).on('submit', '#servicesForm', function() {

return false;

});


// on click on send

$(document).on('click', '#servicesOptions input:checkbox', function() {


if ($('#tickservicehttp').is(':checked') && this.id == "tickservicehttp")
	$('#httpoff').addClass("show");
else
        $(submitServices);

});


//close http drawers anywhere outside of div #service_update
$(document).on('focus click', 'body', function(e) {
    var target = $(e.target);
    var id = e.target.id;

    if (!target.parents('div#services_update').length || id == 'CANCELhttp') {
        $('#httpoff').removeClass("show");
        $('#tickservicehttp').prop('checked', false);
    }
});

// on click on send

$(document).on('click','#httpoff #SENDhttp',function(e) {

        $(submitServices);

});


//NEW PASSWORD

function submitNewpass(){


        $.ajax({
                type: 'POST',
                cache: false,
                url: '?page=newpass',
                data: $('#customPassform').serialize(),
                beforeSend:function(){
                        // this is where we append a loading image
                        jQuery('#security_update').empty();
                        jQuery('#security_update').html('<div class="cbot"><div class="Passloading">Updating...</div></div>');
                },
                success:function(data){
                        // successful request; do something with the data
                        jQuery('#security_update').empty();
                        jQuery('#security_update').html(data);
                },
                error:function(){
                        // failed request; give feedback to user
                        jQuery('#security_update').html('<p class="error"><strong>Oops!</strong> Try that again in a few moments.</p>');
                },
                complete:function(){
               		setTimeout(function() {
				$('#security_update .actiontaken').addClass("actiontakenshrink");
                        },1000);
                }
        });


}


//on submit (browser native enter key) - do nothing, do ajax on key 13 in special field only, not on not browser submit!
$(document).on('submit', '#customPassform', function() {

return false;

});


// on click on send

$(document).on('click','#Passcustom #SENDpass',function(e) {

        $(submitNewpass);

});

// on enter

$(document).on('keypress','#Passcustom #pass1field',function(e) {

        if (e.which == 13)
        {
        $('#pass2field').focus();
        }

});

$(document).on('keypress','#Passcustom #pass2field',function(e) {

         if (e.which == 13)
         {
         $(submitNewpass);
         }

});



//close Security drawers anywhere outside of div #security_update
$(document).on('focus click', 'body', function(e) {
    var target = $(e.target);
    var id = e.target.id;

    if (!target.parents('div#security_update').length || id == 'CANCELpass') {
        $('#Passcustom').removeClass("show");
    }
});

 

// SELECT DNS TEMPLATE

//on('change') geht auch, aber dann nimmt er den bereits ausgewaehlten nicht. man haette die liste auch einfach unausgewaehlt lassen koennen... zu spaet.
$(document).on('click', '#DNSselection input:radio', function() { 
	var DNSselected = $(this).val();
//        alert(DNSselected);

	var useDHCP = '0';
	
	if (DNSselected == "local") { useDHCP = '1'; }
	
	if (DNSselected != "other") {

	$.ajax({
		type: 'POST',
		url: '?page=dns',
		data: { 'action': 'update', 'DNS/useDHCP': useDHCP, 'SmartDNS/selected': DNSselected },
		cache: false,
//		async: false,
		beforeSend:function(){
			// this is where we append a loading image
			jQuery('#dns_update').empty();
			jQuery('#dns_update').html('<div class="cbot"><div class="DNSloading">Updating...</div></div>');
		},
		success:function(data){
			// successful request; do something with the data
//			alert(data);
			jQuery('#dns_update').empty();
			jQuery('#dns_update').html(data);
//			$('#DNSselected').scrollTo($('#'+DNSselected));
//			jQuery('#dns_update').load("?page=dns");;
		},
		error:function(){
			// failed request; give feedback to user
			jQuery('#dns_update').html('<p class="error"><strong>Oops!</strong> Try that again in a few moments.</p>');
		},
		complete:function(){
//		$('#DNSselected').scrollTo($('#'+DNSselected));
//		$('#DNSselected').addClass("hover");
//		$('#DNSselected').scrollTo($('#'+DNSselected));
//		$('#DNSselected').removeClass("hover");
		}
	});

	} else {
		$('#DNScustom').addClass("show");
//		$('#dns1field').focus();
		}

});


