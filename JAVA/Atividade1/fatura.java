package Atividade1;

public class fatura {
    private String numero;
    private String descrição;
    private int qte_item;
    private double preço;

public fatura(String numero, String descrição, int qte_item, double preço){
    this.numero = numero;
    this.descrição = descrição;
    setQte_Item(qte_item);
    setPreço(preço);
}    

public void setNumero(String numero){
    this.numero = numero;
}

public String getNumero(){
    return numero;
}

public void setDescrição(String descrição){
    this.descrição = descrição;
}

public String getDescrição(){
    return descrição;
}

public void setQte_Item(int qte_item){
    if(qte_item > 0){
    this.qte_item = qte_item;
    } else {
        this.qte_item = 0;
    }
}

public int getQte_Item(){
    return qte_item;
}

public void setPreço(double preço){
    if(preço > 0){
    this.preço = preço;
    } else {
        this.preço = 0.0;
    }
}

public double getPreço(){
    return preço;
}

public double getTotalFatura(){
    double total = qte_item * preço;
    return (total > 0.0) ? total : 0.0;
}
}