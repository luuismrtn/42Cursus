
FROM debian:latest

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y nginx

COPY conf /etc/nginx/sites-available/.

CMD ["nginx", "-g", "daemon off;"]