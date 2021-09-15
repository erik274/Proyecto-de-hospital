#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void login(char userF[], char passwordF[]);
void menu1();
void menu2();
void menu3();
int Horarios();

typedef struct HOSPITAL
{
    int identificacion;
    char nombreP[30];
    char apellido[30];
    float edad;
    int telefono;
    int enfermedad;
    char diaconsulta [30] ;
    char horaconsulta [30] ;
} HOSPITAL;

HOSPITAL ingresarInfo(int identificacion,int numhospital);
HOSPITAL enfermedad(int identificacion);

int menu();

int main(void) {
  printf("----------------------SISTEMA HOSPITALARIO DE QUITO------------ \n");
  printf("***************************************************************\n");
  char user[20],password[20];
  printf("Ingresar usuario y contraseña del hospital: \n");
  scanf("%s",user);
  scanf("%s",password);
  login(user,password);
  return 0;
}

void login(char userF[], char passwordF[]) 
{
  if((strcmp(userF,"VACAORTIZ")==0) &&(strcmp(passwordF,"123456")==0))
  {
  int opc;
  do{
  do {
  printf("------------------------APLICACIONES DEL SISTEMA-------------\n");
  printf("1.-MENU PARA PACIENTES DE EMERGENCIAS\n");
  printf("2.-CITAS MEDICAS PARA PERSONAS ASEGURADAS\n");
  printf("3.-MENU PARA DOCTORES(TODAS LA ESPECIALIDADES)\n");
  printf("4.-CERRAR SISTEMA\n");
  scanf("%d", &opc);
  switch (opc){

  case 1:{
  menu1();
  break;}

  case 2:{
  menu2();
  break;}

  case 3:{
  menu3();
  break;}

  case 4:{
  printf("//////////////////////////SISTEMA CERRADO////////////////////// \n");
  break;}
  default:{printf("Opción incorrecta\n");
  break;}}
 }
 while(opc!=4);}
 while (opc!=4);}
  else 
  {
  printf("Usuario o contraseña incorrectos \n");
  printf("///////////////////////////SISTEMA BLOQUEADO//////////////////////// \n");
  }}




void menu1()
{
HOSPITAL hos[100];
    int busqhospital;
    int op,op1;
    int numhospital=0,numcam=0;
    FILE *datos;
     datos = fopen("paciente.txt", "w");
     fprintf(datos,"ID\t NOMBRE\t APELLIDO\tEDAD\tTELEFONO\n");
     fclose(datos);
  do{
    int op = menu();
    switch(op){
      case 1:{
      printf("\n*REGISTRO DE PACIENTES * \n");
      hos[numhospital].identificacion++;
      hos[numhospital] = ingresarInfo(numhospital,numhospital);
      datos = fopen("paciente.txt", "a");
      fprintf(datos,"%d %s %s %1.f %d\n",hos[numhospital].identificacion,hos[numhospital].nombreP,hos[numhospital].apellido,hos[numhospital].edad,hos[numhospital].telefono);
      fclose(datos);
      numhospital++;
      printf("\n");
      break;}
      case 2:
      {
      printf("\n** PACIENTE REGISTRADOS ** \n");
      printf("ID\t NOMBRE\t APELLIDO\tEDAD\tTELEFONO\n");
      printf("-------------------------------------------------------------------------------------------------------\n");
      for(int i=0; i<numhospital; i++){
       printf("%d\t %s\t %s\t\t %1.f\t %d\n",hos[i].identificacion,hos[i].nombreP,hos[i].apellido,hos[i].edad,hos[i].telefono);
      }
      printf("---------------------------------------------------------------------------------------------------------\n");
      printf("\n");
      break;
      }
      case 3:{
      printf("\n** BUSCAR PACIENTE ** \n");
       for(int i=0; i<numhospital; i++){
        printf("%d\t %s\n",
        hos[i].identificacion,hos[i].nombreP);
        }
        printf("INGRESE EL ID DEL PACIENTE\n");
        scanf("%d",&busqhospital);
        printf("%d\n\n",numhospital);
        printf("%d",busqhospital);
        for (int j=0;j<numhospital;j++){
        if (busqhospital==hos[j].identificacion){
        printf("LOS DATOS DEL PACIENTE ES:\n");
        printf("*\n");
        printf("ID\t NOMBRE\t APELLIDO\tEDAD\tTELEFONO\n");
        printf("%d\t %s\t %s\t\t %1.f\t %d\t \n",hos[j].identificacion,hos[j].nombreP,hos[j].apellido,hos[j].edad,hos[j].telefono);}
        }
        printf("\n");
        break;}
     case 4:
      {
      printf ("BIENVENIDO AL REGISTRO DE ENFERMEDAD\n");
      hos[numhospital].identificacion++;
      hos[numhospital] = enfermedad(numhospital);
     break;
      }
      case 5:{
    do
    {
      printf("1. Ingresar numero de camillas\n");
      printf("2. Camillas disponibles\n");
      printf("3. Salir\n");
      scanf("%d",&op1);
      switch(op1)
      {
        case 1:
        {
          printf("Ingresar numero de camillas:");
          scanf( "%d", &numcam );
          if(numhospital<=numcam)
          {
            printf("Valor ingresado es correcto.\n");
          }
          else
          {
            printf("Valor ingresado es correcto.\n");
          }
        }
        break;
        case 2:
        {
          printf("Camillas Disponibles:");
          printf("Total Camillas: %d \n",numcam);
          printf("Total Numero de Pacientes: %d \n",numhospital);
          printf("Total Camillas Disponibles: %d \n",numcam-numhospital);
        }
        break;
      }
    }
    while(op1!=3);
    printf("Gracias por los datos ingresados \n\n");
    break;}
    case 6:
      {printf("GRACIAS POR SU VISITA\n");
     break;}
   default:{printf("Opción incorrecta\n");
   break;}
    }
   }while(op!=6);
}





HOSPITAL ingresarInfo(int identificacion,int numhospital)
{
  HOSPITAL hos; 
  printf("\n Ingrese el nombre del paciente:  ");
    scanf("%s",hos.nombreP);
    printf("\n Ingrese el apellido del paciente :  ");
    scanf("%s",hos.apellido);
    printf("\n Ingrese la edad del paciente:  ");
    scanf("%f",&hos.edad);
    printf("\n Ingrese la telefono del paciente: ");
    scanf("%d",&hos.telefono);
    hos.identificacion++;
  
  return hos;
}

HOSPITAL enfermedad(int identificacion)
{
  HOSPITAL hos;
  printf("ELIGA  AREA PARA REGISTRAR  LA CITA \n");
  printf("1.- ALERGOLOGIA \n");
  printf("2.- CARDIOLOGIA\n");
  printf("3.- Nefrología \n");
  printf("4.- ODONTOLOGIA \n");
  printf("5.- Dermatología \n");
  scanf("%d",&hos.enfermedad);
  
 if (hos.enfermedad==1)
 {
  printf("----------------------------------------------------------------------\n");
   printf("EL DOCTOR DE LA AREA ES : FERNANDO NAVARRETE \n");
     printf("");
    printf("SUS HORARIOS:\n");
    printf("----------------------------------------------------------------------\n");
    printf(" DIAS \t HORA\t\n");
    printf(" LUNES\t  [10H00AM-13:00PM] \n");
    printf(" MARTES\t  [12H00AM-16:00PM] \n");
    printf(" MIERCOLES\t [8H00AM-10:00PM] \n");
    printf(" JUEVES\t  [13H00AM-18:00PM] \n");
    printf(" VIERNES\t  [10H00AM-12:00PM] \n");
    printf("----------------------------------------------------------------------\n");
    printf(" Escoja el dia de su cita\n");
    scanf("%s",hos.diaconsulta);
    printf(" Escoja la hora de la cita\n");
    scanf("%s",hos.horaconsulta);
    printf("----------------------------------------------------------------------\n");
    printf("-->SU CITA ESTA PROGRMADO PARA EL DIA %s A LA HORA %s con el Dr. (FERNANDO NAVARRETE)\n",hos.diaconsulta,hos.horaconsulta);
    printf("----------------------------------------------------------------------\n");
    printf("----GRACIAS SU CITA ESTA AGENDADA---- \n\n");

 }
else if (hos.enfermedad ==2)

 {
 printf("----------------------------------------------------------------------\n");
  printf("EL DOCTOR DE LA AREA ES : KEVIN COSTA \n");
    printf("SUS HORARIOS:\n");
     printf("----------------------------------------------------------------------\n");
    printf(" DIAS \t HORA\t\n");
    printf(" LUNES\t  [8:00AM-10:00PM] \n");
    printf(" MARTES\t  [10:00AM-12:00PM] \n");
    printf(" MIERCOLES\t [11:00AM-13:00PM] \n");
    printf(" JUEVES\t  [13:00PM-15:00PM] \n");
    printf(" VIERNES\t  [18:00PM-20:00PM] \n");
  printf("----------------------------------------------------------------------\n");

    printf(" Escoja el dia de su cita\n");
    scanf("%s",hos.diaconsulta);
     printf("----------------------------------------------------------------------\n");
    printf(" Escoja la hora de la cita\n");
    scanf("%s",hos.horaconsulta);
    printf("");
     printf("----------------------------------------------------------------------\n");
    printf("///SU CITA ESTA PROGRMADO PARA EL DIA %s A LA HORA %s CON EL Dr. (KEVIN COSTA)///\n",hos.diaconsulta,hos.horaconsulta);
     printf("----------------------------------------------------------------------\n");
    printf("----GRACIAS SU CITA ESTA AGENDADO---- \n\n");

 }
else if (hos.enfermedad ==3)

 {
    printf("----------------------------------------------------------------------\n");
  printf("EL DOCTORA DE LA AREA ES : MARIA LUCERO \n");
    printf("SUS HORARIOS:\n");
printf("----------------------------------------------------------------------\n");
    printf(" DIAS \t HORA\t\n");
    printf(" LUNES\t  [7:00AM-10:00PM] \n");
    printf(" MARTES\t  [9:00AM-12:00PM] \n");
    printf(" MIERCOLES\t [10:00AM-13:00PM] \n");
    printf(" JUEVES\t  [14:00PM-15:00PM] \n");
    printf(" VIERNES\t  [12:00PM-15:00PM] \n");
    printf("----------------------------------------------------------------------\n");

    printf(" Escoja el dia de su cita\n");
    scanf("%s",hos.diaconsulta);
    printf(" Escoja la hora de la cita\n");
    scanf("%s",hos.horaconsulta);
     printf("");
 printf("----------------------------------------------------------------------\n");
    printf("///SU CITA ESTA PROGRMADO PARA EL DIA %s A LA HORA %s CON EL Dra. (MARIA LUCERO) ///\n",hos.diaconsulta,hos.horaconsulta);
  printf("----------------------------------------------------------------------\n");
    printf("----GRACIAS SU CITA ESTA AGENDADO---- \n\n");

 }
 else if (hos.enfermedad ==4)

 {
    printf("----------------------------------------------------------------------\n");
  printf("EL DOCTOR DE LA AREA ES : SEBASTIAN JIMENEZ \n");
    printf("SUS HORARIOS:\n");
     printf("----------------------------------------------------------------------\n");
    printf(" DIAS \t HORA\t\n");
    printf(" LUNES\t  [10:00AM-12:00PM] \n");
    printf(" MARTES\t  [9:00AM-12:00PM] \n");
    printf(" MIERCOLES\t [11:00AM-13:00PM] \n");
    printf(" JUEVES\t  [14:00PM-16:00PM] \n");
    printf(" VIERNES\t  [12:00PM-15:00PM] \n");
  printf("----------------------------------------------------------------------\n");

    printf(" Escoja el dia de su cita\n");
    scanf("%s",hos.diaconsulta);
    printf(" Escoja la hora de la cita\n");
    scanf("%s",hos.horaconsulta);
    printf("");
     printf("----------------------------------------------------------------------\n");
    printf("///SU CITA ESTA PROGRMADO PARA EL DIA %s A LA HORA %s CON EL Dr. (SEBASTIAN JIMENEZ)///\n",hos.diaconsulta,hos.horaconsulta);
     printf("----------------------------------------------------------------------\n");
    printf("----GRACIAS SU CITA ESTA AGENDADO---- \n\n");

 }

 else if (hos.enfermedad ==5)

 {
  printf("EL DOCTORA DE LA AREA ES : DAYANA ZAMBRANO \n");
    printf("SUS HORARIOS:\n");
   printf("----------------------------------------------------------------------\n");

    printf(" DIAS \t HORA\t\n");
    printf(" LUNES\t  [7:00AM-10:00PM] \n");
    printf(" MARTES\t  [9:00AM-12:00PM] \n");
    printf(" MIERCOLES\t [10:00AM-13:00PM] \n");
    printf(" JUEVES\t  [14:00PM-15:00PM] \n");
    printf(" VIERNES\t  [12:00PM-15:00PM] \n");
   printf("----------------------------------------------------------------------\n");

    printf(" Escoja el dia de su cita\n");
    scanf("%s",hos.diaconsulta);
    printf(" Escoja la hora de la cita\n");
    scanf("%s",hos.horaconsulta);
     printf("");
   printf("----------------------------------------------------------------------\n");

    printf("///SU CITA ESTA PROGRMADO PARA EL DIA %s A LA HORA %s CON EL Dra. (DAYANA ZAMBRANO)///\n",hos.diaconsulta,hos.horaconsulta);
   printf("----------------------------------------------------------------------\n");

    printf("----GRACIAS SU CITA ESTA AGENDADO---- \n\n");

 }


  
return hos;
}


int menu()
{
        int op;
        printf("\n** Bienvenidos al Sistema del Paciente ** \n");
        printf("\n\t\t Menu principal \n\n");
        printf("1.- Registrar del Paciente \n");
        printf("2.- Listado de Pacientes\n");
        printf("3.- Buscar Paciente\n");
        printf("4.- Registro de Citas \n");
        printf("5.   Registro de Camillas\n");
        printf("6.- Salir\n");
        printf("Ingrese una opción: \n");
        scanf("%d", &op);
        return op;
}





void menu2()
{
Horarios();
}

int Horarios(){
  int  hora;
  char dia [10] ;
 printf("A continuacion se despliegan los horarios de atención que puede pedir su cita\n");
 printf("\n");
 printf("\t\t\tLunes\t Martes\t Miercoles\t Jueves\t Viernes\t \n");
 printf("8AM-9AM\t\t-\t\t\t-\t\t-\t\t\t-\t\t-\n");
 printf("9AM-10AM\t-\t\t\t-\t\t-\t\t\t-\t\t-\n");
 printf("10AM-11AM\t-\t\t\t-\t\t-\t\t\t-\t\t-\n");
 printf("11AM-12AM\t-\t\t\t-\t\t-\t\t\t-\t\t-\n");
 printf("12AM-13PM\t-\t\t\t-\t\t-\t\t\t-\t\t-\n");
 printf("14PM-15PM\t-\t\t\t-\t\t-\t\t\t-\t\t-\n");
 printf("15PM-16PM\t-\t\t\t-\t\t-\t\t\t-\t\t-\n");
 printf("16PM-17PM\t-\t\t\t-\t\t-\t\t\t-\t\t-\n");
 printf("\n");
 printf("Agende el dia de su cita \n");
 scanf("%s",dia);
 printf("Digite la hora escogida \n");
 scanf("%d",&hora);
 if (hora<8){
 printf("Digite en un horario disponible \n");
 printf("Escoja otro hora\n");
 scanf("%d",&hora);
 }
 else if (hora>17){
 printf("Digite en un horario disponible \n");
 printf("Escoja otro hora\n");
 scanf("%d",&hora);
 }
 printf("Se le aparto una cita el dia %s a las %d horas\n",dia, hora);
 printf("==========asistir con 30 minutos de anticipacion=======\n");
  return 0;
}






void menu3()
{
int numerohoras,contadorbucle,sumatoriasueldos,contadordoctores,sumatoriahoras;
float sueldo;
char tipo[3];
int numdoc;
contadorbucle=0;
contadordoctores=0;
sumatoriasueldos=0;
sumatoriahoras=0;
printf("¿CUANTOS DOCTORES SE VAN A REGISTRAR?\n");
scanf("%d",&numdoc);
      while (contadorbucle<numdoc)
       {
       printf("Ingresar el sueldo del doctor %d en su area:\n", contadorbucle+1);
       scanf("%f",&sueldo);
       printf("¿Cuantas horas trabajo el doctor %d  en su especialidad?\n", contadorbucle+1);
       scanf("%d",&numerohoras);
       printf("¿TRABAJA CON PACIENTES CON COVID-19? si o no:\n");
       while (getchar()!='\n');
       fgets(tipo,3,stdin);

       if (strcmp(tipo,"si")==0)
       {
       contadordoctores=contadordoctores+1;
       }

       sumatoriahoras=sumatoriahoras+numerohoras;
       sumatoriasueldos=sumatoriasueldos+sueldo;
       contadorbucle++;
       }
       printf("----------REGISTRO TOTAL DE PAGOS PARA DOCTORES ESTE MES---------\n");
       printf("El total de sueldos para doctores este mes es de:  $ %d\n",sumatoriasueldos);
       printf("El total de horas trabajadas es de:                  %d horas\n",sumatoriahoras);
       printf("Doctores que trabajan con pacientes con COVID-19:    %d \n",contadordoctores);
}
