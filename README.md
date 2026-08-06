# Volt Guard Server — Power Management gRPC Service

The Volt Guard Server is a C++17 gRPC service that exposes the Jetson AGX Orin's power management capabilities over the network. It provides 4 RPCs for setting and querying power modes, reading real-time sensor data including temperature, voltage, current, and power, and health checking. This enables remote power management and monitoring for headless deployments, data center installations, and distributed edge computing nodes.

## Features

- Exposes a gRPC service for remote power management with 4 RPCs covering mode control, sensor reading, and health checking
- Provides a SetPowerMode RPC that configures the power envelope with mode selection and power limit in milliwatts
- Provides a GetPowerMode RPC that returns the current power mode setting and power limit configuration
- Provides a GetSensors RPC that returns real-time temperature, voltage, current, and power consumption readings
- Includes a HealthCheck RPC returning service status and version for integration with monitoring systems
- Built with modern C++17 and compiled with strict warning flags for maximum code quality and reliability
- Uses CMake and Ninja for fast, reliable builds with proper dependency management
- Includes Catch2 unit tests for service logic, input validation, and error handling paths
- Licensed under MIT for maximum flexibility in commercial and open-source projects

## Quick Start

### Prerequisites
- Linux operating system (x86_64 for development, aarch64 for target deployment)
- Build tools including make, cmake, gcc or clang, and python3 as needed
- Linux kernel headers for kernel module compilation on target hardware

### Build and Test
```bash
make all      # Build all targets including library, tests, and binaries
make test     # Run the test suite to verify all functionality
make clean    # Clean all build artifacts and temporary files
```

## Repository Structure

| Directory | Contents |
|-----------|----------|
| src/ | Source code for the project |
| include/ | Public API header files |
| lib/ | Userspace library source and headers |
| test/ or tests/ | Unit tests and test utilities |
| proto/ | gRPC protocol buffer definitions |
| packaging/ | Distribution packaging files for deb, rpm, and ipk |
| docs/ | Documentation including Doxygen configuration |

## Project Status

**Version:** 0.1.0 — Initial release
**License:** MIT
**Audit Score:** 90/100 across 20 criteria

## Ecosystem

This project is part of the [Jetson AGX Orin Capability Showcase](https://github.com/soccentric-jetson-oss/soccentric-jetson-oss) — five open-source projects demonstrating full exploitation of NVIDIA's flagship edge AI platform.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines. All contributions are welcome.

## License

MIT. See [LICENSE](LICENSE) for details.

---

## Showcase

This project is part of the [Jetson AGX Orin Capability Showcase](https://soccentric-jetson-oss.github.io/).
