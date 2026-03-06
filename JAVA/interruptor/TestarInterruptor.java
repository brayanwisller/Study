public class TestarInterruptor {
    public static void main (String [] args){
        Interruptor testeInterruptor;
        testeInterruptor = new Interruptor();

        testeInterruptor.pressionar();
        testeInterruptor.verificarLampada();

        testeInterruptor.pressionar();
        testeInterruptor.verificarLampada();
    }
}
