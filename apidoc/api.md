GET 	/api/v1/msg/?user_id=102
�������� ��������� ���������.
���� ��������:
	200 - �k
	400 - Bad request
�������� ������:
	{ 
	  "msgs" : [
			{ 
			  "user_id": 105,
			  "msg_content" : "bla bla bla" 
			},
			{ 
			  "user_id": 108,
			  "msg_content" : "HELLO =)"
			} 
		   ]
	}


POST 	/api/v1/msg/new/	
��������� ����� ���������.
������� ������: 
	{
		"user_id": 102,
		"msg_content": "tra ta ta"
	}
���� ��������:
	200 - �k
	400 - Bad request 


POST 	/api/v1/users/new/?nick=blabla
���������� ������ ������������ � �����-�� �������.  
�������� ������: 
	{
		"user_id": 309
	}
���� ��������:
	200 - �k
	400 - Bad request 
