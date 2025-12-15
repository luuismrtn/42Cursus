# Developer Documentation

## Prerequisites

- Host system with Docker Engine 24+ and Docker Compose plugin installed.
- GNU Make, OpenSSL, and access to port 443 (ensure no conflicting services).
- Ability to run commands with `sudo` to edit `/etc/hosts` and manage bind-mounted directories.

## Repository Layout

- `Makefile`: orchestrates host preparation, container lifecycle, and cleanup.
- `srcs/docker-compose.yml`: defines the nginx, wordpress (PHP-FPM), and mariadb services.
- `srcs/requirements/*/Dockerfile`: image definitions for each service.
- `srcs/requirements/*/conf`: runtime configuration files copied into the images.
- `srcs/requirements/*/tools`: bootstrap scripts executed as container entrypoints.
- `srcs/.env`: environment defaults consumed by Docker Compose and setup scripts.

## Initial Setup

- Clone the repository and create a copy of `srcs/.env` if customization is required.
- Adjust credentials (`MYSQL_*`, `WP_*`) in `.env` for the target deployment.
- Ensure `/home/$USER/data` exists or let the `Makefile` create it during the first run.

## Build and Launch Workflow

- Run `make` to:
  - Append the hostname mapping to `/etc/hosts`.
  - Create host directories under `/home/$USER/data/{wordpress,mariadb}` with `www-data` ownership.
  - Build images using the Dockerfiles and start the stack in the foreground.
- Run `make re` to rebuild from scratch (equivalent to `make fclean` followed by `make`).
- Use `make down` to stop the stack without removing persistent data.

## Container and Volume Management

- Compose shortcuts: `docker compose -f srcs/docker-compose.yml ps`, `logs`, `exec <service> sh`, or `restart <service>`.
- Inspect volumes:
  - WordPress content: `/home/$USER/data/wordpress`
  - MariaDB datadir: `/home/$USER/data/mariadb`
- To prune everything, run `make fclean`; this removes containers, images, named volumes, and host bind paths.
- Regenerate TLS assets by deleting `/home/$USER/data/wordpress/` and rerunning `make` (nginx `setup.sh` recreates certificates).

## Persistence and Data Flow

- Bind mounts (configured in `docker-compose.yml`) map host directories to container paths, allowing inspection during development and ensuring data survives container rebuilds.
- WordPress PHP files and uploads persist under `/var/www/html` -> `/home/$USER/data/wordpress`.
- MariaDB stores its InnoDB files under `/var/lib/mysql` -> `/home/$USER/data/mariadb`.
- TLS certificates generated on container startup live in the nginx container at `/etc/nginx/ssl`; rebuild nginx to refresh them if needed.
