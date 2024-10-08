#include <stdio.h>
#include <string.h>

#define MAX_LIVRES 100

typedef struct {
    char titre[50];
    char auteur[50];
    float prix;
    int quantite;
} Livre;
    int nombreLivres = 0;     
    void ajouteLivre(){

   Livre stock[MAX_LIVRES]; 
void add (){
        if (nombreLivres < MAX_LIVRES) {
                    printf("Entrez le titre du livre: ");
                    scanf(" %[^\n]", &stock[nombreLivres].titre);
                    printf("Entrez l'auteur du livre: ");
                    scanf(" %[^\n]",&stock[nombreLivres].auteur);
                    printf("Entrez le prix du livre: ");
                    scanf("%f", &stock[nombreLivres].prix);
                    printf("Entrez la quantité en stock: ");
                    scanf("%d", &stock[nombreLivres].quantite);
                    nombreLivres++;
                } else {
                    printf("Le stock est plein !\n");
                }
}}

int main() {
 
    int choix;

    do {
        printf("\n---- Menu Principal ----\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher tous les livres\n");
        printf("3. Rechercher un livre par titre\n");
        printf("4. Mettre à jour la quantité d'un livre\n");
        printf("5. Supprimer un livre\n");
        printf("6. Afficher le nombre total de livres en stock\n");
        printf("0. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouteLivre();
                break;

            case 2:

                if (nombreLivres == 0) {
                    printf("Aucun livre n'est disponible.\n");
                } else {
                    printf("Liste des livres disponibles:\n");
                    for (int i = 0; i < nombreLivres; i++) {
                        printf("Titre: %s, Auteur: %s, Prix: %.2f, Quantité: %d\n",
                               stock[i].titre, stock[i].auteur, stock[i].prix, stock[i].quantite);
                    }
                }
                break;

            case 3: {

                char titre[50];
                printf("Entrez le titre du livre à rechercher: ");
                scanf(" %[^\n]", titre);

                int livreTrouve = 0;
                for (int i = 0; i < nombreLivres; i++) {
                    if (strcmp(stock[i].titre, titre) == 0) {
                        printf("Livre trouvé: Titre: %s, Auteur: %s, Prix: %.2f, Quantité: %d\n",
                               stock[i].titre, stock[i].auteur, stock[i].prix, stock[i].quantite);
                        livreTrouve = 1;
                        break;
                    }
                }
                if (!livreTrouve) {
                    printf("Livre non trouvé.\n");
                }
                break;
            }

            case 4: {

                char titre[50];
                int nouvelleQuantite;
                printf("Entrez le titre du livre à mettre à jour: ");
                scanf(" %[^\n]", titre);

                int livreTrouve = 0;
                for (int i = 0; i < nombreLivres; i++) {
                    if (strcmp(stock[i].titre, titre) == 0) {
                        printf("Entrez la nouvelle quantité: ");
                        scanf("%d", &nouvelleQuantite);
                        stock[i].quantite = nouvelleQuantite;
                        printf("Quantité mise à jour avec succès.\n");
                        livreTrouve = 1;
                        break;
                    }
                }
                if (!livreTrouve) {
                    printf("Livre non trouvé.\n");
                }
                break;
            }

            case 5: {

                char titre[50];
                printf("Entrez le titre du livre à supprimer: ");
                scanf(" %[^\n]", titre);

                int livreTrouve = 0;
                for (int i = 0; i < nombreLivres; i++) {
                    if (strcmp(stock[i].titre, titre) == 0) {
                        for (int j = i; j < nombreLivres - 1; j++) {
                            stock[j] = stock[j + 1];  
                        }
                        nombreLivres--;
                        printf("Livre supprimé avec succès.\n");
                        livreTrouve = 1;
                        break;
                    }
                }
                if (!livreTrouve) {
                    printf("Livre non trouvé.\n");
                }
                break;
            }

            case 6: {

                int total = 0;
                for (int i = 0; i < nombreLivres; i++) {
                    total += stock[i].quantite;
                }
                printf("Nombre total de livres en stock: %d\n", total);
                break;
            }

            case 0:

                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }

    } while (choix != 0);

    return 0;
}


