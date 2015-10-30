GET 	/api/v1/msg 	
Получить последние сообщения.
Коды возврата:
	200 - Оk
	400 - Bad request
Выходной формат:
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
Отправить новое сообщение. Сообщение ограниченной длины, любого символьного содержания.
Входной формат: 
	{
		"user_id": 15,
		"room_id": 3,
		"msg_content": "tra ta ta"
	}
Коды возврата:
	200 - Оk
	400 - Bad request (отправка большей длины сообщения)


