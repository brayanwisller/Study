package Atividade4;

public class InteiroSet {
    private boolean[] conjunto;

public InteiroSet(){
    conjunto = new boolean[101];
}

public InteiroSet union(InteiroSet OutroConjunto){
    InteiroSet união = new InteiroSet();

    for(int i = 0; i < conjunto.length; i++){
        união.conjunto[i] = this.conjunto[i] || OutroConjunto.conjunto[i];
    }

    return união;
}

public InteiroSet intersecção(InteiroSet OutroConjunto){
    InteiroSet intersecção = new InteiroSet();

    for(int i = 0; i < conjunto.length; i++){
        intersecção.conjunto[i] = this.conjunto[i] && OutroConjunto.conjunto[i];
    }

    return intersecção;
}

public void InsereElemento(int elemento){
    if(elemento >= 0 && elemento <= 100){
        conjunto[elemento] = true;
    } else {
        System.out.println("Elemento está fora do proposto (0 - 100)");
    }
}

public void DeletaElemento(int elemento){
    if(elemento >= 0 && elemento <= 100){
        conjunto[elemento] = false;
    } else {
        System.out.println("Elemento está fora do proposto (0 - 100)");
    }
}

public String toSetString(){
    StringBuilder sb = new StringBuilder();
        boolean isEmpty = true;

        for (int i = 0; i < conjunto.length; i++) {
            if (conjunto[i]) {
                sb.append(i).append(" ");
                isEmpty = false;
            }
        }

        if (isEmpty) {
            return "-";
        } else {
            return sb.toString().trim();
        }
}

public boolean ehIgualTo(InteiroSet OutroConjunto){
    for(int i = 0; i < conjunto.length; i++){
        if(this.conjunto[i] != OutroConjunto.conjunto[i]){
            return false;
        }
    }
    return true;
}
}
