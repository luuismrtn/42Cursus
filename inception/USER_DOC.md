# User Documentation

## Stack Overview

- **Nginx** terminates TLS on port 443 and serves the WordPress site.
- **WordPress (PHP-FPM)** runs the application code behind Nginx and executes PHP scripts.
- **MariaDB** stores WordPress content, users, and configuration data.
- Services communicate over an isolated Docker network; data persists on the host under `/home/$USER/data`.

## Starting and Stopping the Stack

- Run `make` to add the hostname entry, prepare data directories, build images, and start the containers.
- Use `make down` to stop every container while keeping the data on disk.
- Run `make fclean` when you need a full reset of containers, images, and persistent data.
- Execute `make clean-hosts` to remove the custom hostname entry from `/etc/hosts` after teardown.

## Accessing the Website and Administration Panel

- Once the stack is running, browse to `https://lumartin.42.fr/` to reach the public site.
- The WordPress administration dashboard is available at `https://lumartin.42.fr/wp-admin`.
- The TLS certificate is self-signed; accept the browser warning on first access.

## Credentials Location and Management

- Default administrator and user credentials are stored in `srcs/.env`.
- Update the following keys in `srcs/.env` before deployment:
  - `WP_ADMIN_USER`, `WP_ADMIN_PASSWORD`, `WP_ADMIN_EMAIL`
  - `WP_USER`, `WP_USER_PASSWORD`, `WP_USER_EMAIL`
  - `MYSQL_DATABASE`, `MYSQL_USER`, `MYSQL_PASSWORD`
- After editing `.env`, rerun `make fclean` followed by `make` to propagate new credentials.

## Verifying Service Health

- Run `docker compose -f srcs/docker-compose.yml ps` to confirm containers are running (state should be `up`).
- Use `make logs` to follow real-time logs from all services and spot configuration issues.
- Check HTTPS availability with `curl -kI https://lumartin.42.fr/` (the `-k` flag ignores the self-signed certificate warning).
- Confirm database readiness from within the WordPress container: `docker compose -f srcs/docker-compose.yml exec wordpress mysqladmin ping -h mariadb -u "$MYSQL_USER" -p"$MYSQL_PASSWORD"`.
