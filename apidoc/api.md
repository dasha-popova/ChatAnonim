GET 	/api/v1/msg 	
�������� ��������� ���������.
���� ��������:
	200 - �k
	400 - Bad request
�������� ������:
	{ 
	  "msgs" : [
			{ 
			  "msg_id" : 1, 
			  "user_id": 15,
			  "room_id" : 3,
			  "msg_content" : "bla bla bla" 
			},
			{ 
			  "msg_id" : 2,
			  "user_id": 38,
			  "room_id" : 3,
			  "msg_content" : "HELLO =)"
			} 
		   ]
	}


POST 	/api/v1/msg/new	
��������� ����� ���������. ��������� ������������ �����, ������ ����������� ����������.
������� ������: 
	{
		"user_id": 15,
		"room_id": 3,
		"msg_content": "tra ta ta"
	}
���� ��������:
	200 - �k
	400 - Bad request (�������� ������� ����� ���������)


