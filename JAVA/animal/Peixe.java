public class Peixe extends Animal{
    private String caracteristca;

    public Peixe(String nome, double comprimento, int numPatas, String cor, String ambiente, double velocidadeMedia, String caracterstica){
        super(nome, comprimento, numPatas, cor, ambiente, velocidadeMedia);
        this.caracteristca = caracterstica;
    }

    public void setCaracteristica(String caracteristica){
        this.caracteristca = caracteristica;
    }
    public String getcaracteristica(){
        return caracteristca;
    }

    public String toString2(){
        return toString1() +
        ", caracteristica: " + caracteristca + 
        "}";
    }    
}
