jQuery('#DNSselected').click(function(){
	jQuery.ajax({
		type: 'POST',
		url: 'http://kyleschaeffer.com/feed/',
		data: { postVar1: 'theValue1', postVar2: 'theValue2' },
		beforeSend:function(){
			// this is where we append a loading image
			jQuery('#dns').html('<div class="loading"><img src="http://www.kyleschaeffer.com/wp-content/uploads/2010/04/loading.gif" alt="Loading..." /></div>');
		},
		success:function(data){
			// successful request; do something with the data
			jQuery('#dns').empty();
			jQuery(data).find('item').each(function(i){
				jQuery('#dns').append('<h4>' + jQuery(this).find('title').text() + '</h4><p>' + jQuery(this).find('link').text() + '</p>');
			});
		},
		error:function(){
			// failed request; give feedback to user
			jQuery('#dns').html('<p class="error"><strong>Oops!</strong> Try that again in a few moments.</p>');
		}
	});
});

