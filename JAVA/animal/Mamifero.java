public class Mamifero extends Animal{
    private String alimento;

    public Mamifero(String nome, double comprimento, int numPatas, String cor, String ambiente, double velocidadeMedia, String alimento){
        super(nome, comprimento, numPatas, cor, ambiente, velocidadeMedia);
        this.alimento = alimento;
    }

    public void setAlimento(String alimento){
        this.alimento = alimento;
    }
    public String getAlimento(){
        return alimento;
    }

    public String toString(){
        return toString1() +
        ", alimento: " + alimento +
        "}";
    }
}
