GET 	/api/v1/msg/?user_id=102
�������� ��������� ���������.
���� ��������:
	200 - �k
	400 - Bad request
�������� ������:
	{ 
	  "msgs" : [
			{ 
			  "msg_id" : 4, 
			  "user_id": 105,
			  "room_id" : 3,
			  "msg_content" : "bla bla bla" 
			},
			{ 
			  "msg_id" : 5,
			  "user_id": 108,
			  "room_id" : 3,
			  "msg_content" : "HELLO =)"
			} 
		   ]
	}


POST 	/api/v1/msg/new/?user_id=102	
��������� ����� ���������. ��������� ������������ �����, ������ ����������� ����������.
������� ������: 
	{
		"user_id": 102,
		"msg_content": "tra ta ta"
	}
���� ��������:
	200 - �k
	400 - Bad request (�������� ������� ����� ���������)


