GET 	/api/v1/msg?room_id=3&&msg_id=3 	
�������� ��������� ���������.
���� ��������:
	200 - �k
	400 - Bad request
�������� ������:
	{ 
	  "msgs" : [
			{ 
			  "msg_id" : 4, 
			  "user_id": 15,
			  "room_id" : 3,
			  "msg_content" : "bla bla bla" 
			},
			{ 
			  "msg_id" : 5,
			  "user_id": 38,
			  "room_id" : 3,
			  "msg_content" : "HELLO =)"
			} 
		   ]
	}


POST 	/api/v1/msg/new?room_id=3	
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


