_This project has been created as part of the 42 curriculum by lumartin._

## Description

- Docker-based reproduction of the classic LEMP stack required by the 42 Inception project.
- Builds isolated containers for Nginx, WordPress (PHP-FPM), and MariaDB with TLS and persistent storage.
- Automates provisioning via Makefile targets so evaluators can launch and clean the stack quickly.

## Project Description

- **Docker Usage**: Each service is defined in `srcs/docker-compose.yml` and built from custom Dockerfiles under `srcs/requirements`. A dedicated network isolates internal traffic while TLS terminates at the Nginx container.
- **Included Sources**: Custom configs live under `srcs/requirements/*/conf`, bootstrap scripts under `srcs/requirements/*/tools`, and environment defaults in `srcs/.env`.
- **Design Choices**: Minimal base images to limit footprint, bind-mounted volumes for visibility during defense, and idempotent setup scripts so restarts stay consistent.
- **Virtual Machines vs Docker**: VMs ship full guest kernels and hardware virtualization, resulting in heavier resource usage and slower boot. Docker containers share the host kernel, start in seconds, and simplify orchestrating multiple services on one host.
- **Secrets vs Environment Variables**: Secrets (for example Docker secrets or dedicated vaults) remain encrypted at rest and in transit, while plain environment variables expose values to `docker inspect` and process listings. Here `.env` is used for simplicity during evaluation, but production deployments should adopt secrets management.
- **Docker Network vs Host Network**: A custom bridge network keeps inter-service communication private and allows service discovery by container name. Host networking would collapse that isolation and could conflict with host ports.
- **Docker Volumes vs Bind Mounts**: Named volumes abstract storage and can move across hosts, whereas bind mounts map exact host paths for transparency. This project uses bind-like driver options to keep data under `/home/$USER/data` for easier inspection during grading.

## Instructions

- Dependencies: Docker ≥ 24 and Docker Compose plugin, GNU Make, and HTTPS port 443 available on the host.
- Bootstrap: run `make` to append the hostname, create volumes with correct permissions, and build/start the stack.
- Teardown: use `make down` to stop containers, `make fclean` to wipe data and volumes, and `make clean-hosts` to drop the host entry.
- Logs & Debugging: `make logs` streams combined service logs; individual container shells are accessible via `docker compose -f srcs/docker-compose.yml exec <service> sh`.

## Resources

- Docker Docs: https://docs.docker.com/get-started/overview/
- Nginx SSL Configuration: https://nginx.org/en/docs/http/configuring_https_servers.html
- WordPress on Docker Guide: https://developer.wordpress.org/advanced-administration/server/docker/
- MariaDB Configuration: https://mariadb.com/kb/en/configuring-mariadb-with-option-files/
