import serial 

################################################################# main
p_serial = serial.Serial(port= 'COM6', baudrate=57600)

################################################################# ciclo 

while (1): 
    letra_enviada = input("Envia una letra: ")
    p_serial.write(letra_enviada.encode())    


    letra_recibida = p_serial.readline().decode()
    letra_recibida =letra_recibida[:-1]
    if (len(letra_recibida) > 0): 
        print(letra_recibida)

        for i in range(0, len(letra_recibida)): 
            print(letra_recibida[len(letra_recibida)-1-i], end= '')
            print(i+1, end= '')
        print("\n")
