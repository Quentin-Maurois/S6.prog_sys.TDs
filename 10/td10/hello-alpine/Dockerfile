# Version d'alpine-3.17.3
FROM alpine:3.17.3

# Définir le nom et le tag de l'image
LABEL tag="alpine-3.17"

# Partage de la bibliothèque c
RUN apk add gcompat

# Copier le fichier hello.exe dans le conteneur
COPY hello.exe /app/hello.exe

# Exécuter hello.exe lorsque le conteneur est lancé
CMD ["/app/hello.exe"]
