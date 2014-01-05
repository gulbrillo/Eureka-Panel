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


//submit custom DNS

$(document).on('click','#DNScustom #SENDcustomDNS',function(e) {
var form = $('#customDNSform');
var data = form.serialize();


        $.ajax({
                type: 'POST',
                url: '?page=dns',
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



});


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
//		chache: false,
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

	} else {$('#DNScustom').addClass("show");}

});
