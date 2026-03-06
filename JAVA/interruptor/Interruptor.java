public class Interruptor {
    boolean ligado = false;

    void pressionar(){
        if(ligado = false){
            ligado = true;
        } else {
            ligado = false;
        }
    }

    void verificarLampada(){
        if(ligado = true){
            System.out.println("A luz está acesa.");
        } else {
            System.out.println("A luz está apagada.");
        }
    }
}