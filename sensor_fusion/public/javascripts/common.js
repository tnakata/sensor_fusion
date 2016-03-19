$(document).ready(function() {
	$(".process_request").click(function() {
		var id = $(this).attr('id');
		$.ajax({
			method: 'POST',
			url:	'/',
			data:	{id: id},
			dataType: 'json',
			success: function(data) {
				alert(data.msg);
			},
			error: function(data) {
				alert('error');
			}
		})	
	})
});
