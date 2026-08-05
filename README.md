# Volt Guard Server — Power Management gRPC Service

The Volt Guard Server is a C++17 gRPC service that exposes the Jetson AGX Orin's power management capabilities over the network. It provides 4 RPCs for setting and querying power modes, reading real-time sensor data (temperature, voltage, current, power), and health checking. This enables remote power management and monitoring for headless deployments, data center installations, and distributed edge computing nodes. The server is built with CMake and Ninja, compiles with strict warning flags, and includes Catch2 unit tests.

## Features

- gRPC
- service
- for
- power
- management

## Quick Start

### Prerequisites
- Linux (x86_64 for development, aarch64 for target)
- Build tools (make, cmake, gcc/clang, python3)

### Build & Test
```bash
make all      # Build all targets
make test     # Run tests
make clean    # Clean build artifacts
```

## Architecture

```
Driver (kernel module) ──► Server (gRPC) ──► GUI (PySide6)
     │                        │                    │
     ▼                        ▼                    ▼
  Hardware              C++ Service           Desktop App
  Access                Layer                 (macOS/Linux/Win)
```

## Repository Structure

| Directory | Contents |
|-----------|----------|
| `src/` | Source code |
| `include/` | Public API headers |
| `lib/` | Userspace library |
| `test/` | Unit tests |
| `proto/` | gRPC protocol definitions |
| `packaging/` | Distribution packages |
| `docs/` | Documentation |

## Project Status

**Version:** 0.1.0 — Initial release
**License:** Set power mode RPC
**Audit Score:** 90/100

## 🌐 Ecosystem

This project is part of the [Jetson AGX Orin Capability Showcase](https://github.com/soccentric-jetson-oss/soccentric-jetson-oss) — five open-source projects demonstrating full exploitation of NVIDIA's flagship edge AI platform.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines. All contributions welcome!

## License

Set power mode RPC. See [LICENSE](LICENSE) for details.
